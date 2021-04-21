from abc import abstractmethod
from io import FileIO
from typing import Dict, List, Optional
from enum import Enum
import os
import json
import stat

class SubmissionStatus(Enum):
    NONE = 0
    SUCCESS = 1
    TIMEOUT = 2
    FAILURE = 3
    BUILD_ERROR = 4

    @staticmethod
    def fromString(s: str) -> Optional['SubmissionStatus']:
        if s == "":return SubmissionStatus.NONE
        if s == "SUCCESS":return SubmissionStatus.SUCCESS
        if s == "TIME_OUT":return SubmissionStatus.TIMEOUT
        if s == "FAILURE":return SubmissionStatus.FAILURE
        if s == "BUILD_ERROR":return SubmissionStatus.BUILD_ERROR
        raise Exception(f"{s} is not a supported submission status.")
    
class Language(Enum):
    PYTHON = 1
    PYTHON3 = 2
    C = 3

    def toExtension(self):
        if self in [Language.PYTHON, Language.PYTHON3]:return 'py'
        elif self == Language.C: return 'c'

    def execute(self, fileName, compilationFlags):
        if self in [Language.PYTHON, Language.PYTHON3]:
            return [f'python3 {fileName}']
        elif self == Language.C:
            baseName = os.path.splitext(fileName)[0]
            return [f'''
export LD_LIBRARY_PATH=/usr/local/lib/x86_64-linux-gnu
gcc *.c -o {baseName} -lcriterion {compilationFlags} && ./{baseName}
''']

    @staticmethod
    def fromString(s: str) -> 'Language':
        if s.upper() == "PYTHON":return Language.PYTHON
        if s.upper() == "PYTHON3":return Language.PYTHON3
        if s.upper() == "C":return Language.C
        raise Exception(f"{s} is not a supported language.")

class TestingInfo:
    @abstractmethod
    def save(self, activity: 'Activity', path: str):
        ...

class IOTest:
    def __init__(self, id: int, name: str, input: str, output: str):
        self.id = id
        self.name = name
        self.input, self.output = input, output

    @classmethod
    def fromJson(cls, data):
        return cls(data['id'], data['name'], data['in'], data['out'])
    
    def toJson(self):
        return {'id': self.id, 'name': self.name, 'in': self.input, 'out': self.output}

    def __repr__(self):
        return self.name

class IOTests(TestingInfo):
    def __init__(self, tests: List[IOTest]):
        self.tests = tests
    
    def save(self, activity: 'Activity', path: str):
        with open(os.path.join(path, 'tests.txt'), 'w') as file:
            json.dump([test.toJson() for test in self.tests], file)

    def __repr__(self):
        return f'IO Tests: {repr([repr(test) for test in self.tests])}'

class UnitTest(TestingInfo):
    def __init__(self, language: Language, testContent: str):
        self.language = language
        self.testContent = testContent
    
    def save(self, activity: 'Activity', path: str):
        ext = self.language.toExtension()
        testFile = os.path.join(path, f'test.{ext}')
        with open(testFile, 'w') as file:
            file.write(self.testContent)
            if self.language in [Language.PYTHON, Language.PYTHON3]:
                file.write('\n\nif __name__=="__main__":unittest.main()')
            
        runFile = os.path.join(path, 'test.sh')
        with open(runFile, 'w') as file:
            file.write('#!/bin/bash\n')
            commands = self.language.execute(os.path.relpath(testFile, path), activity.compilationFlags or "")
            file.writelines(commands)
        st = os.stat(runFile)
        os.chmod(runFile, st.st_mode | stat.S_IEXEC)

    def __repr__(self):
        return f'Unit Test: {self.testContent[:20]}'

class Activity:
    def __init__(self, id: int, course_id: int, category_id: int, 
            category_name: str, category_description: str, name: str, 
            description: str, language: Language, is_iotested: bool, active: bool, 
            deleted: bool, points: int, file_id: int, 
            date_created: str, last_updated: str, 
            testing_info: Optional[TestingInfo], 
            submission_status: Optional[SubmissionStatus],
            compilation_flags: Optional[str]):
        self.id = id
        self.courseId = course_id
        self.categoryId = category_id
        self.categoryName = category_name
        self.categoryDescription = category_description
        self.name = name
        self.description = description
        self.language = language
        self.isIotested = is_iotested
        self.active = active
        self.deleted = deleted
        self.points = points
        self.fileId = file_id
        self.dateCreated = date_created
        self.lastUpdated = last_updated
        self.submissionStatus = submission_status
        self.testingInfo = testing_info
        self.compilationFlags = compilation_flags


    @classmethod
    def fromJson(cls, data):
        language = Language.fromString(data["language"])
        testingInfo = None
        if "activity_iotests" in data and data["activity_iotests"]:
            print(data["activity_iotests"])
            testingInfo = IOTests([IOTest.fromJson(test) for test in data["activity_iotests"]])
        elif "activity_unit_tests" in data and data["activity_unit_tests"]:
            testingInfo = UnitTest(language, data["activity_unit_tests"])

        submissionStatus = None
        if "submission_status" in data:
            submissionStatus = SubmissionStatus.fromString(data["submission_status"])

        return cls(
            data["id"],
            data["course_id"],
            data["category_id"],
            data["category_name"],
            data["category_description"],
            data["name"],
            data["description"],
            language,
            data["is_iotested"],
            data["active"],
            data["deleted"],
            data["points"],
            data["file_id"],
            data["date_created"],
            data["last_updated"],
            compilation_flags = data["compilation_flags"] if "compilation_flags" in data else None,
            testing_info = testingInfo,
            submission_status = submissionStatus
        )

    def __repr__(self):
        return f'"{self.name}"'


class Files:
    def __init__(self, fileDict: Dict[str, str]):
        self.fileDict = fileDict
    
    def save(self, path):
        for name, content in self.fileDict.items():
            with open(os.path.join(path, name), 'w') as file:
                file.write(content)

    @classmethod
    def fromJson(cls, data: Dict[str, str]):
        copy = data.copy()
        del copy['files_metadata']
        return cls(copy)