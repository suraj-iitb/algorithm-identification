import os

algo = ['linear', 'binary', 'bfs', 'dfs']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        os.system("./svm_learn -t 5 -C T ../Data/Searching/AST/"+algo[i]+"_"+algo[j]+".train ../Models/Searching/"+algo[i]+"_"+algo[j]+".model")
        j += 1