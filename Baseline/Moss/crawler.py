import requests
import json

############# Variables ############
path = 'Data/Insertion/Dump/'
name = 'insertion'
ext = '.cpp'
code_id = 'code-id.txt'
####################################

with open(path+code_id, 'r') as ids:
    for id in ids:
        id = id.strip()
        r = requests.get('https://judgeapi.u-aizu.ac.jp/reviews/'+id)
        r = json.loads(r.text)
        code = r['sourceCode']

        with open(path+name+id+ext, 'w') as f:
            f.write(code)

