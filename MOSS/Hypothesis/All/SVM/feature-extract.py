import os

limit = 10

algorithm = {'bubble':[], 'insertion':[], 'selection':[], 'counting':[], 'merge':[], 'quick':[]}
lines = []

with open('../Results/all/10/10.csv', 'r') as f:
    for line in f:
        lines.append(line.strip())
# print(lines)

with open('../Results/all/10/10_svm.csv', 'w') as s:
    for algo in os.listdir('../../../Data'):
        count = 1
        for code in os.listdir('../../../Data/' + algo + '/Dump'):
            if not code.endswith('.txt'):
                temp = []
                if count <= limit:
                    # print(code)
                    for line in lines:
                        line = line.strip().split(',')
                        if line[0] == code:
                            print(line[0])
                            temp.append(str([line[2],line[1]]))
                        if line[2] == code:
                            print(line[2])
                            temp.append(str([line[0],line[3]]))
                    s.write(code + ',' + ','.join(temp) + '\n')
                    count += 1
                else:
                    break
        # break

        



 