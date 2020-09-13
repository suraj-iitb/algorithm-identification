import os

with open('Results/max-avg/max-avg.csv', 'w') as op:
    for file in os.listdir('Results/max-avg/'):
        if file != 'max-avg.csv':
            
            sum = 0
            mx = -1000
            mn = 1000
            pers = []

            with open('Results/max-avg/' + file) as f:
                for line in f:
                    pers.append(int(line.strip().split(',')[1]))
                for per in pers:
                    sum += per
                    if mx < per:
                        mx = per
                    if mn > per:
                        mn = per
                sum /= len(pers)

            op.write(file[:-4]+','+str(sum)+','+str(mx)+','+str(mn)+'\n')

