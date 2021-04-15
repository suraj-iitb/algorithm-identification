import os

algo = ['bubble', 'insertion', 'selection', 'counting', 'merge', 'quick']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        os.system("./svm_classify ../Data1/AST/algo-r1.test ../Models1/"+algo[i]+"_"+algo[j]+".model ../Prediction1/"+algo[i]+"_"+algo[j]+"-r1.pred")
        j += 1