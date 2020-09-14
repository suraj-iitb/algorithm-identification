d = {'b':[], 'i':[], 's':[], 'q':[], 'm':[], 'c':[]}

path = 'Results/all/10/10'

with open('Results/max-avg/max-avg.csv') as f:
    for line in f:
        line = line.strip().split(',')
        if line[0].startswith('b'):
            d['b'].append(float(line[1]))
            d['b'].append(float(line[3]))
        elif line[0].startswith('i'):
            d['i'].append(float(line[1]))
            d['i'].append(float(line[3]))
        elif line[0].startswith('s'):
            d['s'].append(float(line[1]))
            d['s'].append(float(line[3]))
        elif line[0].startswith('q'):
            d['q'].append(float(line[1]))
            d['q'].append(float(line[3]))
        elif line[0].startswith('m'):
            d['m'].append(float(line[1]))
            d['m'].append(float(line[3]))
        elif line[0].startswith('c'):
            d['c'].append(float(line[1]))
            d['c'].append(float(line[3]))

# Hyp 1
with open(path+'_scores.csv') as g:
    with open(path+'_labels_hyp1.csv', 'w') as f:
        for line in g:
            line = line.strip().split(',')
            if float(line[1])>=d['b'][0] and float(line[3])<d['i'][0] and float(line[5])<d['s'][0] and \
                float(line[7])<d['q'][0] and float(line[9])<d['m'][0] and float(line[11])<d['c'][0] :
                f.write(line[0]+ ',bubble\n')
            elif float(line[1])<d['b'][0] and float(line[3])>=d['i'][0] and float(line[5])<d['s'][0] and \
                float(line[7])<d['q'][0] and float(line[9])<d['m'][0] and float(line[11])<d['c'][0] :
                f.write(line[0]+ ',insertion\n')
            elif float(line[1])<d['b'][0] and float(line[3])<d['i'][0] and float(line[5])>=d['s'][0] and \
                float(line[7])<d['q'][0] and float(line[9])<d['m'][0] and float(line[11])<d['c'][0] :
                f.write(line[0]+ ',selection\n')
            elif float(line[1])<d['b'][0] and float(line[3])<d['i'][0] and float(line[5])<d['s'][0] and \
                float(line[7])>=d['q'][0] and float(line[9])<d['m'][0] and float(line[11])<d['c'][0] :
                f.write(line[0]+ ',quick\n')
            elif float(line[1])<d['b'][0] and float(line[3])<d['i'][0] and float(line[5])<d['s'][0] and \
                float(line[7])<d['q'][0] and float(line[9])>=d['m'][0] and float(line[11])<d['c'][0] :
                f.write(line[0]+ ',merge\n')
            elif float(line[1])<d['b'][0] and float(line[3])<d['i'][0] and float(line[5])<d['s'][0] and \
                float(line[7])<d['q'][0] and float(line[9])<d['m'][0] and float(line[11])>=d['c'][0] :
                f.write(line[0]+ ',counting\n')
            else:
                f.write(line[0]+ ',none\n')

# Hyp 2
with open(path+'_scores.csv') as g:
    with open(path+'_labels_hyp2.csv', 'w') as f:
        for line in g:
            line = line.strip().split(',')
            if float(line[1])>=d['b'][1] and float(line[3])<d['i'][1] and float(line[5])<d['s'][1] and \
                float(line[7])<d['q'][1] and float(line[9])<d['m'][1] and float(line[11])<d['c'][1] :
                f.write(line[0]+ ',bubble\n')
            elif float(line[1])<d['b'][1] and float(line[3])>=d['i'][1] and float(line[5])<d['s'][1] and \
                float(line[7])<d['q'][1] and float(line[9])<d['m'][1] and float(line[11])<d['c'][1] :
                f.write(line[0]+ ',insertion\n')
            elif float(line[1])<d['b'][1] and float(line[3])<d['i'][1] and float(line[5])>=d['s'][1] and \
                float(line[7])<d['q'][1] and float(line[9])<d['m'][1] and float(line[11])<d['c'][1] :
                f.write(line[0]+ ',selection\n')
            elif float(line[1])<d['b'][1] and float(line[3])<d['i'][1] and float(line[5])<d['s'][1] and \
                float(line[7])>=d['q'][1] and float(line[9])<d['m'][1] and float(line[11])<d['c'][1] :
                f.write(line[0]+ ',quick\n')
            elif float(line[1])<d['b'][1] and float(line[3])<d['i'][1] and float(line[5])<d['s'][1] and \
                float(line[7])<d['q'][1] and float(line[9])>=d['m'][1] and float(line[11])<d['c'][1] :
                f.write(line[0]+ ',merge\n')
            elif float(line[1])<d['b'][1] and float(line[3])<d['i'][1] and float(line[5])<d['s'][1] and \
                float(line[7])<d['q'][1] and float(line[9])<d['m'][1] and float(line[11])>=d['c'][1] :
                f.write(line[0]+ ',counting\n')
            else:
                f.write(line[0]+ ',none\n')


# Hyp 3
with open(path+'_scores.csv') as g:
    with open(path+'_labels_hyp3.csv', 'w') as f:
        for line in g:
            line = line.strip().split(',')
            if float(line[2])>=d['b'][0] and float(line[4])<d['i'][0] and float(line[6])<d['s'][0] and \
                float(line[8])<d['q'][0] and float(line[10])<d['m'][0] and float(line[12])<d['c'][0] :
                f.write(line[0]+ ',bubble\n')
            elif float(line[2])<d['b'][0] and float(line[4])>=d['i'][0] and float(line[6])<d['s'][0] and \
                float(line[8])<d['q'][0] and float(line[10])<d['m'][0] and float(line[12])<d['c'][0] :
                f.write(line[0]+ ',insertion\n')
            elif float(line[2])<d['b'][0] and float(line[4])<d['i'][0] and float(line[6])>=d['s'][0] and \
                float(line[8])<d['q'][0] and float(line[10])<d['m'][0] and float(line[12])<d['c'][0] :
                f.write(line[0]+ ',selection\n')
            elif float(line[2])<d['b'][0] and float(line[4])<d['i'][0] and float(line[6])<d['s'][0] and \
                float(line[8])>=d['q'][0] and float(line[10])<d['m'][0] and float(line[12])<d['c'][0] :
                f.write(line[0]+ ',quick\n')
            elif float(line[2])<d['b'][0] and float(line[4])<d['i'][0] and float(line[6])<d['s'][0] and \
                float(line[8])<d['q'][0] and float(line[10])>=d['m'][0] and float(line[12])<d['c'][0] :
                f.write(line[0]+ ',merge\n')
            elif float(line[2])<d['b'][0] and float(line[4])<d['i'][0] and float(line[6])<d['s'][0] and \
                float(line[8])<d['q'][0] and float(line[10])<d['m'][0] and float(line[12])>=d['c'][0] :
                f.write(line[0]+ ',counting\n')
            else:
                f.write(line[0]+ ',none\n')

# Hyp 4
with open(path+'_scores.csv') as g:
    with open(path+'_labels_hyp4.csv', 'w') as f:
        for line in g:
            line = line.strip().split(',')
            if float(line[2])>=d['b'][1] and float(line[4])<d['i'][1] and float(line[6])<d['s'][1] and \
                float(line[8])<d['q'][1] and float(line[10])<d['m'][1] and float(line[12])<d['c'][1] :
                f.write(line[0]+ ',bubble\n')
            elif float(line[2])<d['b'][1] and float(line[4])>=d['i'][1] and float(line[6])<d['s'][1] and \
                float(line[8])<d['q'][1] and float(line[10])<d['m'][1] and float(line[12])<d['c'][1] :
                f.write(line[0]+ ',insertion\n')
            elif float(line[2])<d['b'][1] and float(line[4])<d['i'][1] and float(line[6])>=d['s'][1] and \
                float(line[8])<d['q'][1] and float(line[10])<d['m'][1] and float(line[12])<d['c'][1] :
                f.write(line[0]+ ',selection\n')
            elif float(line[2])<d['b'][1] and float(line[4])<d['i'][1] and float(line[6])<d['s'][1] and \
                float(line[8])>=d['q'][1] and float(line[10])<d['m'][1] and float(line[12])<d['c'][1] :
                f.write(line[0]+ ',quick\n')
            elif float(line[2])<d['b'][1] and float(line[4])<d['i'][1] and float(line[6])<d['s'][1] and \
                float(line[8])<d['q'][1] and float(line[10])>=d['m'][1] and float(line[12])<d['c'][1] :
                f.write(line[0]+ ',merge\n')
            elif float(line[2])<d['b'][1] and float(line[4])<d['i'][1] and float(line[6])<d['s'][1] and \
                float(line[8])<d['q'][1] and float(line[10])<d['m'][1] and float(line[12])>=d['c'][1] :
                f.write(line[0]+ ',counting\n')
            else:
                f.write(line[0]+ ',none\n')