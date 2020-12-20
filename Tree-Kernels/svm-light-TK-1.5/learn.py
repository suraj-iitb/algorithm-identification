import os

algo = ['bubble', 'insertion', 'selection', 'counting', 'merge', 'quick']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        os.system("./svm_learn -t 5 -C T ../Data/AST/"+algo[i]+"_"+algo[j]+".train ../Models/"+algo[i]+"_"+algo[j]+".model")
        j += 1