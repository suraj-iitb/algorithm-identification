import os
import shutil

algo = 'BFS'
inp1 = 'input-' + algo
out1 = 'output-' + algo

# data = os.listdir('../MOSS/Data/')
# for algo in data:
print(algo)
for file in os.listdir('../MOSS/Data/Searching/'+algo+'/C'):
    print(file)
    if file.endswith('.c'):
        os.makedirs(inp1)
        os.system('cp ../MOSS/Data/Searching/'+algo+'/C/' + file + ' ' + inp1)
        os.system('joern-parse ' + inp1 + ' --out ' + inp1 + '/cpg.bin')
        os.system('joern-export ' + inp1 + '/cpg.bin ' + '--repr cfg --out ' + out1)
        dot_files = os.listdir(out1)
        for dot_file in dot_files:
            with open(out1 + '/'+dot_file, 'r') as f:
                temp = f.readlines()
                if len(temp) == 3:
                    continue
                else:
                    with open(out1 + '/out.dot', 'w') as out:
                        out.write(''.join(temp))
                    os.system('graph-easy ' + out1 +'/out.dot --graphml --out CFG/Searching/'+ algo + '/' + file.split('.')[0] + '.graphml')

        shutil.rmtree(inp1)
        shutil.rmtree(out1)
    # break
# break
