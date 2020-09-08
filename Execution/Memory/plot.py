import os
from matplotlib import pyplot as plt

for d1 in os.listdir('Results'):
    for file in os.listdir('Results/'+d1):
        if file.endswith('.csv'):
            with open('Results/'+d1+'/'+file, 'r') as f:
                x = []
                y = []
                for line in f:
                    line = line.strip().split(',')
                    if len(line) != 0:
                        x.append(int(line[0]))
                        y.append(float(line[1]))
                        
                plt.scatter(x, y, label=d1+" sort")
                plt.xlabel('n')
                plt.ylabel('S (bytes)')
                plt.legend()
plt.savefig('Figures/all.png')
