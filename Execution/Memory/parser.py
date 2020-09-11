import os

for d1 in os.listdir('Results'):
    with open('Results/' + d1 + '/' + d1 + '-dump.csv', 'w') as op:
        for file in os.listdir('Results/'+d1):
            if file.endswith('.read'):

                lines = []
                results = []
                sum = 0.0

                with open('Results/' + d1 + '/' + file) as f:
                    for line in f:
                        line = line.strip()
                        if line != '':
                            line = line.split(' ')
                            line = [l.replace(',','') for l in line if l != '']
                            lines.append(line)

                for i in range(len(lines)):
                    if lines[i][0] == 'n':
                        results.append(lines[i+2])

                for r in results:
                    r = float(r[2])
                    sum += r
                sum /= len(results)
                
                if not file.startswith('quick-iter'):
                    input = file[:-5].split('-')[1]
                else:
                    input = file.split('-')[2]
                if input in ['10000', '50000', '100000']:
                    op.write(input + ',' + str(sum) + '\n')