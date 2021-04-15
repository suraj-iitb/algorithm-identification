algo = ['bubble', 'insertion', 'selection', 'counting', 'merge', 'quick']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        with open(algo[i]+'_'+algo[j]+'.train', 'w') as ans:
            with open(algo[i]+'_'+algo[j]+'.test', 'w') as ans1:
                # Algo1
                count = 0
                with open(algo[i]+'.ast', 'r') as f:
                    lines = f.read().strip().split('\n')
                    for line in lines:
                        count += 1
                        line = line.split(' ')
                        line[0] = '1'
                        if (count %6 == 0):
                            ans.write(' '.join(line)+'\n')
                        else:
                            ans1.write(' '.join(line)+'\n')
                # Algo2
                count = 0
                with open(algo[j]+'.ast', 'r') as f:
                    lines = f.read().strip().split('\n')
                    for line in lines:
                        count += 1
                        line = line.split(' ')
                        line[0] = '-1'
                        if (count %6 == 0):
                            ans.write(' '.join(line)+'\n')
                        else:
                            ans1.write(' '.join(line)+'\n')
        j += 1
