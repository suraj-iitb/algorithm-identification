import os
import random

algorithm = {'bubble':[], 'insertion':[], 'selection':[], 'counting':[], 'merge':[], 'quick':[]}
lines = []

with open('../Results/all/100/100.csv', 'r') as f:
    for line in f:
        lines.append(line.strip())
# print(lines)

with open('../Results/all/100/100_svm.csv', 'w') as s:
    for algo in os.listdir('../../../Data'):
        if not algo.endswith('.txt'):
            count = 1
            limit = random.randrange(100)
            print(algo, limit)
            for code in os.listdir('../../../Data/' + algo + '/Dump/CPP'):
                if not code.endswith('.txt'):
                    temp = []
                    if count <= limit:
                        # print(code)
                        for line in lines:
                            line = line.strip().split(',')
                            if line[0] == code:
                                # print(line[0])
                                temp.append(line[2])
                                temp.append(line[1])
                            if line[2] == code:
                                # print(line[2])
                                temp.append(line[0])
                                temp.append(line[3])
                        s.write(code + ',' + ','.join(temp) + '\n')
                        count += 1
                    else:
                        break
            # break

            



 