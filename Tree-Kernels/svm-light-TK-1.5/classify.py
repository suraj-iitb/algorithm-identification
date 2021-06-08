import os

algo = ['linear', 'binary', 'bfs', 'dfs']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        os.system("./svm_classify ../Data/Searching/AST/"+algo[i]+"_"+algo[j]+".test ../Models/Searching/"+algo[i]+"_"+algo[j]+".model ../Prediction/Searching/"+algo[i]+"_"+algo[j]+".pred")
        j += 1