codes = set()
lines = []
d = {'b':[], 'i':[], 's':[], 'q':[], 'm':[], 'c':[]}
# dict_max = {'b':0, 'i':0, 's':0, 'q':0, 'm':0, 'c':0}
# print(d.keys())

path = 'Results/all/100/100'

with open(path+'.csv') as f:
    for line in f:
        line = line.strip().split(',')
        lines.append(line)
        codes.add(line[0])
        codes.add(line[2])
# print(codes)
# print(len(codes))

with open(path+'_scores.csv', 'w') as f:
    for code in codes:
        for l in lines:
            if code == l[0]:
                print(code,l)
                if l[2].startswith('b'):
                    d['b'].append(int(l[1]))
                elif l[2].startswith('i'):
                    d['i'].append(int(l[1]))
                elif l[2].startswith('s'):
                    d['s'].append(int(l[1]))
                elif l[2].startswith('q'):
                    d['q'].append(int(l[1]))
                elif l[2].startswith('m'):
                    d['m'].append(int(l[1]))
                elif l[2].startswith('c'):
                    d['c'].append(int(l[1]))
            elif code == l[2]:
                print(code,l)
                if l[0].startswith('b'):
                    d['b'].append(int(l[3]))
                elif l[0].startswith('i'):
                    d['i'].append(int(l[3]))
                elif l[0].startswith('s'):
                    d['s'].append(int(l[3]))
                elif l[0].startswith('q'):
                    d['q'].append(int(l[3]))
                elif l[0].startswith('m'):
                    d['m'].append(int(l[3]))
                elif l[0].startswith('c'):
                    d['c'].append(int(l[3]))
        f.write(code)
        for i in d.keys():
            print(i)
            if len(d[i]) > 0:
                f.write(',' + str(sum(d[i])/len(d[i])) + ',' + str(max(d[i])))
                d[i].clear()
            else:
                f.write(',0,0')
        f.write('\n')
