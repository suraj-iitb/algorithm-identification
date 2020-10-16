import random

algo = ['bubble', 'insertion', 'selection', 'counting', 'merge', 'quick']

with open('algo-r2.test', 'w') as ans:
    for i in range(0, len(algo)):
        with open(algo[i]+'.ast', 'r') as f:
            lines = f.read().split('\n')
            for line in lines[701: 701+random.randrange(80)]:
                line = line.split(' ')
                line[0] = str(i)
                ans.write(' '.join(line)+'\n')