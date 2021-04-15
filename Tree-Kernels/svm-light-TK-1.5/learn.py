import os

algo = ['bubble', 'insertion', 'selection', 'counting', 'merge', 'quick']

for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        os.system("./svm_learn -t 5 -C T ../Data1/AST/"+algo[i]+"_"+algo[j]+".train ../Models1/"+algo[i]+"_"+algo[j]+".model")
        j += 1