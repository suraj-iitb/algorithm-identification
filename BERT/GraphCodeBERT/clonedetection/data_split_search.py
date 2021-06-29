import os

no = 6
cnt = {"Linear": 0, "Binary": 0, "BFS": 0, "DFS": 0}
f1 = open('train.txt')
f2 = open('valid.txt')
f3 = open('test.txt')
count = 0
with open('log.txt', 'w') as f:
    for algo in os.listdir('Data_Dump'):
        algo_path = os.path.join('Data_Dump', algo)
        for lang in os.listdir(algo_path):
            if lang == "C":
                lang_path = os.path.join(algo_path, lang, 'Code')
                for file in os.listdir(lang_path):
                    file_path = os.path.join(lang_path, file)
                    print(file_path)
                    f.write(file_path+"\n")
                    if algo == 'Linear':
                        f1.write(str(count)+"\t0\n")
                        f2.write(str(count)+"\t0\n")
                        f3.write(str(count)+"\t0\n")
                        cnt["Linear"] += 1
                        if cnt["Linear"] % no == 0:
                            os.system('echo -n "0<CODESPLIT>Linear Search<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "0<CODESPLIT>Linaer Search<CODESPLIT>" >> data.txt')
                    elif algo == 'Binary':
                        f1.write(str(count)+"\t1\n")
                        f2.write(str(count)+"\t1\n")
                        f3.write(str(count)+"\t1\n")
                        cnt["Binary"] += 1
                        if cnt["Binary"] % no == 0:
                            os.system('echo -n "1<CODESPLIT>Binary Search<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "1<CODESPLIT>Binary Search<CODESPLIT>" >> data.txt')
                    elif algo == 'BFS':
                        f1.write(str(count)+"\t2\n")
                        f2.write(str(count)+"\t2\n")
                        f3.write(str(count)+"\t2\n")
                        cnt["BFS"] += 1
                        if cnt["BFS"] % no == 0:
                            os.system('echo -n "2<CODESPLIT>BFS<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "2<CODESPLIT>BFS<CODESPLIT>" >> data.txt')
                    elif algo == 'DFS':
                        f1.write(str(count)+"\t3\n")
                        f2.write(str(count)+"\t3\n")
                        f3.write(str(count)+"\t3\n")
                        cnt["DFS"] += 1
                        if cnt["DFS"] % no  == 0:
                            os.system('echo -n "3<CODESPLIT>DFS<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "3<CODESPLIT>DFS<CODESPLIT>" >> data.txt')

                    cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                    os.system(cmd)
                    count += 1
f1.close()
f2.close()
f3.close()