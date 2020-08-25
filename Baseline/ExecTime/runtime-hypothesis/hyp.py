import os

for dir in os.listdir('Results'):
    for file in os.listdir('Results/'+dir):
        print('**********************')
        print(dir+'/'+file)
        sum = 0
        count = 0
        if 'tau+delta' in file:
            with open('Results/'+dir+"/"+file) as f:
                with open('Results/'+dir+"/tot"+file[9:], 'w') as g:
                    for line in f:
                        sum += float(line.strip())
                        count += 1
                        g.write(str(sum/count)+'\n')

