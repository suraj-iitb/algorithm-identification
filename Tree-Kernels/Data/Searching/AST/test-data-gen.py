import random

algo = ['linear', 'binary', 'bfs', 'dfs']

with open('algo-r1.test', 'w') as ans:
    for i in range(0, len(algo)):
        with open(algo[i]+'.ast', 'r') as f:
            lines = f.read().split('\n')
            for line in lines[501: 501+random.randrange(50)]:
                line = line.split(' ')
                line[0] = str(i)
                ans.write(' '.join(line)+'\n')