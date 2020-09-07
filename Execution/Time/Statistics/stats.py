import numpy as np
import os

ci = [(90, 1.660), (95, 1.984), (99, 2.626)]

for d1 in os.listdir('Result'):
    with open('Result/'+ d1 + '/' + d1 + '_stats', 'w') as b:
        for file in os.listdir('Result/'+d1):
            if file.endswith('processed'):
                b.write(file.split('_')[1] + ',')
                with open('Result/'+d1+'/'+file, 'r') as f:
                    list = []
                    for t in f:
                        if t.strip() != '':
                            list.append(float(t.strip()))
                    array = np.array(list)
                    mean = np.mean(array)
                    sd = np.std(array)
                    b.write("%.2f" % float(mean) + ',')
                    b.write("%.2f" % float(sd) + ',')
                    for c in ci:
                        moe = (c[1] * sd) / np.sqrt(array.shape[0])
                        b.write("%.2f" % float(moe) + ',')
                    b.write("\n")