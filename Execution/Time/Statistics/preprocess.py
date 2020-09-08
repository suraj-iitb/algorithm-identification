import os

count = 0
cpu = 0.0

for d1 in os.listdir('Result'):
    for file in os.listdir('Result/'+d1):
        if not file.endswith('processed'):
            with open('Result/'+d1+'/'+file, 'r') as f:
                with open('Result/'+d1+'/'+file+'_processed', 'w') as g:
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
                                cpu += (float(min) * 60 + float(sec)) * 1000
                            if count == 4:
                                g.write(str(cpu)+'\n')