import requests
import json

####### Variables ########
problemId = 'GRL_1_C'
language = 'c++14'
id_file = 'Data/Path/All/C/code-id.txt'
##########################

r = requests.get('https://judgeapi.u-aizu.ac.jp/solutions/problems/' + problemId + '/lang/' + language +'/rating?page=0&size=10000')
solutions = json.loads(r.text)

with open(id_file, 'a') as ids:
    for solution in solutions:
        if solution['policy'] == 'private':
            continue
        solution_id = solution['judgeId']
        ids.write(str(solution_id)+'\n')