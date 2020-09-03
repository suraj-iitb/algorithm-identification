import requests
import json

####### Variables ########
problemId = 'ALDS1_2_D'
language = 'c%2B%2B'
id_file = 'Data/Shell/Dump/code-id.txt'
##########################

r = requests.get('https://judgeapi.u-aizu.ac.jp/solutions/problems/' + problemId + '/lang/' + language +'/rating?page=0&size=10000')
solutions = json.loads(r.text)

with open(id_file, 'w') as ids:
    for solution in solutions:
        if solution['policy'] == 'private':
            continue
        solution_id = solution['judgeId']
        ids.write(str(solution_id)+'\n')