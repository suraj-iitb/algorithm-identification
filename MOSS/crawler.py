import requests
import json

############# Variables ############
path = 'Data/Searching/DFS/C/'
name = 'dfs'
ext = '.c'
code_id = 'code-id.txt'
####################################

with open(path+code_id, 'r') as ids:
    count = 1
    for id in ids:
        print('Count:', count)
        id = id.strip()
        r = requests.get('https://judgeapi.u-aizu.ac.jp/reviews/'+id)
        r = json.loads(r.text)
        code = r['sourceCode']

        with open(path+name+id+ext, 'w') as f:
            f.write(code)
        count += 1

