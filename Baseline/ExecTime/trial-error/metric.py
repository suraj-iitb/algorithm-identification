import numpy as np

input_list = [10, 100, 1000, 10000, 100000]

ci = [(90, 1.645), (95, 1.960), (99, 2.576)]
algo = 'quick-runtime/quick_'

with open(algo + 'stats', 'w') as b:
    for size in input_list:
        list = []
        b.write('For input size: ' + str(size) + '\n')
        with open(algo +str(size)+'_processed', 'r') as f:
            for t in f:
                if t.strip() != '':
                    list.append(float(t.strip()))
        array = np.array(list)
        mean = np.mean(array)
        sd = np.std(array)
        b.write("Mean: " + "%.16f" % float(mean) + ' milli sec\n')
        b.write("Std Deviation: " + "%.16f" % float(sd) + ' milli sec\n')
        for c in ci:
            moe = (c[1] * sd) / np.sqrt(array.shape[0])
            b.write("Margin of Error for " + str(c[0]) + "% CI: " + "%.16f" % float(moe) + ' milli sec\n')
        b.write("\n")