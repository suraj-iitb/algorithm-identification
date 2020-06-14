import requests
import json

with open('Data/BubbleSort/Dump/code-id', 'r') as ids:
    for id in ids:
        id = id.strip()
        r = requests.get('https://judgeapi.u-aizu.ac.jp/reviews/'+id)
        r = json.loads(r.text)
        code = r['sourceCode']

        with open('Data/BubbleSort/Dump/bubble-'+id+'.cpp', 'w') as f:
            f.write(code)

