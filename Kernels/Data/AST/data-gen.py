algo = ['bubble', 'insertion', 'selection', 'counting', 'merge', 'quick']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        with open(algo[i]+'_'+algo[j]+'.train', 'w') as ans:
            # Algo1
            count = 0
            with open(algo[i]+'.ast', 'r') as f:
                lines = f.read().split('\n')
                for line in lines:
                    count += 1
                    line = line.split(' ')
                    line[0] = '1'
                    ans.write(' '.join(line)+'\n')
                    if (count == 500):
                        break
            # Algo2
            count = 0
            with open(algo[j]+'.ast', 'r') as f:
                lines = f.read().split('\n')
                for line in lines:
                    count += 1
                    line = line.split(' ')
                    line[0] = '-1'
                    ans.write(' '.join(line)+'\n')
                    if (count == 500):
                        break
        j += 1
        break
    break
