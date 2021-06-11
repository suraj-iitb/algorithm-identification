algo = ['all', 'ss']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        with open(algo[i]+'_'+algo[j]+'.train', 'w') as ans:
            with open(algo[i]+'_'+algo[j]+'.test', 'w') as ans1:
                # Algo1
                count = 0
                with open(algo[i]+'.ast', 'r') as f:
                    lines = f.read().split('\n')
                    for line in lines:
                        count += 1
                        line = line.split(' ')
                        line[0] = '1'
                        if (count <=300):
                            ans.write(' '.join(line)+'\n')
                        elif (count > 500 and count <= 550):
                            ans1.write(' '.join(line)+'\n')
                        else:
                            continue
                # Algo2
                count = 0
                with open(algo[j]+'.ast', 'r') as f:
                    lines = f.read().split('\n')
                    for line in lines:
                        count += 1
                        line = line.split(' ')
                        line[0] = '-1'
                        if (count <=300):
                            ans.write(' '.join(line)+'\n')
                        elif (count > 500 and count <= 550):
                            ans1.write(' '.join(line)+'\n')
                        else:
                            continue
        j += 1
