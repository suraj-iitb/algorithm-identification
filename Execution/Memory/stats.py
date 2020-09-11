import numpy as np
import os

ci = [(90, 1.660), (95, 1.984), (99, 2.626)]

for d1 in os.listdir('Results'):
    with open('Results/'+ d1 + '/' + d1 + '-stats.csv', 'w') as b:
        for file in os.listdir('Results/'+d1):
            if file.endswith('-dump.csv'):
                with open('Results/'+d1+'/'+file, 'r') as f:
                    d = {'10000':[], '50000':[], '100000':[]}
                    for t in f:
                        if t.strip() != '':
                            t = t.strip().split(',')
                            d[t[0]].append(float(t[1]))

                    for i in list(d.keys()):
                        array = np.array(d[i])
                        mean = np.mean(array)
                        sd = np.std(array)
                        b.write(i + ',')
                        b.write("%.2f" % float(mean) + ',')
                        b.write("%.2f" % float(sd) + ',')
                        for c in ci:
                            moe = (c[1] * sd) / np.sqrt(array.shape[0])
                            b.write("%.2f" % float(moe) + ',')
                        b.write("\n")