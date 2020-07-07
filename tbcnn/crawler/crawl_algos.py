import sys
import os

if len(sys.argv) != 2:
    print('Usage: python crawl_algos_id.py <language>')
    exit(1)

language = sys.argv[1]

with open('algorithms.txt', 'r') as f:
    algos = f.readlines()
    for algo in algos[1:]:
        algo = algo.strip().split(',')
        problemId = algo[0]
        algorithm = algo[2]
        print('-------------------------------------------------------------------------')
        print(problemId, algorithm, language)
        print('-------------------------------------------------------------------------')
        os.system('python3 crawler.py ' + problemId + ' ' + language + ' ' + algorithm)
