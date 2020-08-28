count = 0
cpu = 0.0
input_list = [10, 100, 1000, 10000, 100000]
algo = 'quick-runtime/quick_'

for size in input_list:
    with open(algo +str(size), 'r') as f:
        with open(algo +str(size)+'_processed', 'w') as g:
            for line in f:
                line = line.strip()
                if line == '':
                    count = 1
                    cpu = 0.0
                else:
                    count += 1
                    if count == 3 or count == 4:
                        line = line.split('\t')[1].split('m')
                        min = line[0]
                        sec = line[1][:-1]
                        # print(min, sec)
                        cpu += (float(min) * 60 + float(sec)) * 10e3
                    if count == 4:
                        g.write(str(cpu)+'\n')