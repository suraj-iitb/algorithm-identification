import numpy as np
import os

ci = [(90, 1.660), (95, 1.984), (99, 2.626)]

for d1 in os.listdir('Result'):
    with open('Result/'+ d1 + '/' + d1 + '_stats', 'w') as b:
        for file in os.listdir('Result/'+d1):
            if file.endswith('processed'):
                b.write('Input size: ' + file.split('_')[1] + '\n')
                with open('Result/'+d1+'/'+file, 'r') as f:
                    list = []
                    print('Result/'+d1+'/'+file)
                    for t in f:
                        if t.strip() != '':
                            list.append(float(t.strip()))
                    array = np.array(list)
                    mean = np.mean(array)
                    sd = np.std(array)
                    b.write("Mean: " + "%.16f" % float(mean) + ' ms\n')
                    b.write("Standard deviation: " + "%.16f" % float(sd) + ' ms\n')
                    for c in ci:
                        moe = (c[1] * sd) / np.sqrt(array.shape[0])
                        b.write("Margin of Error for " + str(c[0]) + "% CI: " + "%.16f" % float(moe) + ' ms\n')
                    b.write("\n")