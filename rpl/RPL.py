 
import requests
from requests.sessions import Session
from activity import Activity, Files, SubmissionStatus
import os
import json

        

class Client:
    def __init__(self, token: str, session = requests.Session()):
        self.token = token
        self.s = session


    def getActivities(self):
        return [Activity.fromJson(act) for act in self.getJson('http://www.rpl.codes/api/courses/11/activities')]
        
    def getSingleActivity(self, id: int):
        return Activity.fromJson(self.getJson(f'http://www.rpl.codes/api/courses/11/activities/{id}'))
    
    def getFiles(self, id: int):
        return Files.fromJson(self.getJson(f'http://www.rpl.codes/api/getFileForStudent/{id}'))

    def getJson(self, url: str):
        fileName = os.path.join('data', f'{url[25:].replace("/", ".")}.json')
        if not os.path.exists(fileName):
            print('Downloading file...')
            res = self.s.get(url, headers={'authorization': f'Bearer {self.token}'})
            with open(fileName, 'w') as file:
                json.dump(res.json(), file, indent='\t')
        with open(fileName) as file:
            return json.load(file)

    @classmethod
    def fromCredentials(cls, email: str, password: str):
        s = requests.Session()
        res = s.post('http://www.rpl.codes/api/auth/login', json={'username_or_email': email, 'password': password})
        return cls(res.json()['access_token'])

    
# def get_default_token():
#     with open('token.txt') as tokenFile:
#         return tokenFile.readline()


# if __name__ == "__main__":
#     c = Client.fromCredentials('ilitteri@fi.uba.ar', 'password')
#     act = c.getActivities()
    
