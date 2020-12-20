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
            limit = 100 #random.randrange(100)
            print(algo, limit)
            for code in os.listdir('../../../Data/' + algo + '/Dump/CPP'):
                if not code.endswith('.txt'):
                    temp = []
                    for algo1 in os.listdir('../../../Data'):
                        if not algo1.endswith('.txt'):
                            for code1 in os.listdir('../../../Data/' + algo1 + '/Dump/CPP'):
                                if not code1.endswith('.txt'):
                                    # if count <= limit:
                                        # print(code)
                                    flag = False
                                    for line in lines:
                                        line = line.strip().split(',')
                                        flag = False
                                        if line[0] == code1 and line[2] == code:
                                            # print(line[0])
                                            temp.append(line[0])
                                            temp.append(line[1])
                                            flag = True
                                            break
                                        if not flag and line[2] == code1 and line[0] == code:
                                            # print(line[2])
                                            temp.append(line[2])
                                            temp.append(line[3])
                                            flag = True
                                            break
                                    if not flag:
                                        temp.append(code1)
                                        temp.append('0')
                                            # temp.append(line[0])
                                            # temp.append('0')
                    s.write(code + ',' + ','.join(temp) + '\n')
                                    # count += 1
                                # else:
                                #     break
                        # break

                



    