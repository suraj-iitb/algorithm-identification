import os

limit = 75

algorithm = {'bubble':[], 'insertion':[], 'selection':[], 'counting':[], 'merge':[], 'quick':[]}
lines = []

with open('../Results/all/75/75.csv', 'r') as f:
    for line in f:
        lines.append(line.strip())
# print(lines)

with open('../Results/all/75/75_svm.csv', 'w') as s:
    for algo in os.listdir('../../../Data'):
        count = 1
        for code in os.listdir('../../../Data/' + algo + '/Dump'):
            if not code.endswith('.txt') and not code.endswith('C'):
                temp = []
                if count <= limit:
                    # print(code)
                    for line in lines:
                        line = line.strip().split(',')
                        if line[0] == code:
                            print(line[0])
                            temp.append(line[2])
                            temp.append(line[1])
                        if line[2] == code:
                            print(line[2])
                            temp.append(line[0])
                            temp.append(line[3])
                    s.write(code + ',' + ','.join(temp) + '\n')
                    count += 1
                else:
                    break
        # break

        



 