import requests
import json
import sys
import os

if len(sys.argv) !=4:
    print('Usage: python crawl_solutions_id.py <problemId> <language> <algorithm>')
    exit(1)

problemId = sys.argv[1]
language = sys.argv[2]
algorithm = sys.argv[3]

directory = os.path.join('data', algorithm, language)
id_file = os.path.join(directory, algorithm + '_ids_' + language + '.txt')

# directory checks
if not os.path.exists(directory):
    os.makedirs(directory)

r = requests.get('https://judgeapi.u-aizu.ac.jp/solutions/problems/' + problemId + '/lang/' + language +'/rating?page=0&size=10000')
solutions = json.loads(r.text)

with open(id_file, 'w') as ids:
    for solution in solutions:
        if solution['policy'] == 'private':
            continue
        solution_id = solution['judgeId']
        ids.write(str(solution_id)+'\n')

with open(id_file, 'r') as ids:
    for id in ids:
        id = id.strip()
        if id != '':
            r = requests.get('https://judgeapi.u-aizu.ac.jp/reviews/'+id)
            r = json.loads(r.text)
            code = r['sourceCode']

            code_file  = os.path.join(directory, algorithm + id + '.cpp')
            with open(code_file, 'w') as c:
                c.write(code)

            print('Crawled:', code_file)