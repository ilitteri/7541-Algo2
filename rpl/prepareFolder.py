import json
from typing import DefaultDict, List
from activity import Activity, Language, SubmissionStatus, UnitTest
from RPL import Client
import os
import time

with open('credentials.json') as credentialsFile:
    credentials = json.load(credentialsFile)
c = Client.fromCredentials(credentials['email'], credentials['password'])
all_activities = c.getActivities()
#solved_activities = [act for act in activities if act.submissionStatus != SubmissionStatus.NONE]

basePath = 'Exercises'
if not os.path.exists(basePath):
    os.mkdir(basePath)

categories: DefaultDict[str, List[Activity]] = DefaultDict(lambda:[])
for activity in all_activities:
    categories[activity.categoryName].append(activity)

for category, activities in categories.items():
    categoryPath = os.path.join(basePath, category)
    if not os.path.exists(categoryPath):
        os.mkdir(categoryPath)
        categoryDescription = activities[0].categoryDescription
        if categoryDescription:
            with open(os.path.join(categoryPath, 'description.md'), 'w') as descriptionFile:
                descriptionFile.write(categoryDescription)
    
    print(f'Saving category: {category}')
    for activity in activities:
        exercisePath = os.path.join(categoryPath, activity.name)
        if os.path.exists(exercisePath):continue
        os.mkdir(exercisePath)
        
        print(f'Saving activity: {activity.name}')
        copy = c.getSingleActivity(activity.id)
        activity.testingInfo = copy.testingInfo
        activity.compilationFlags = copy.compilationFlags
        files = c.getFiles(activity.fileId)

        files.save(exercisePath)
        if activity.testingInfo is not None:
            activity.testingInfo.save(activity, exercisePath)
        
        with open(os.path.join(exercisePath, 'description.md'), 'w') as descriptionFile:
            descriptionFile.write(activity.description)
    