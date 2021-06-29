import os

no = 10
cnt = {"Linear": 0, "Binary": 0, "BFS": 0, "DFS": 0}
with open('log.txt', 'w') as f:
    for algo in os.listdir('Data_Dump/Searching/Searching'):
        algo_path = os.path.join('Data_Dump/Searching/Searching', algo)
        for lang in os.listdir(algo_path):
            if lang == "C":
                lang_path = os.path.join(algo_path, lang)
                for file in os.listdir(lang_path):
                    if not file.endswith('.txt'):
                        file_path = os.path.join(lang_path, file)
                        print(file_path)
                        f.write(file_path+"\n")
                        if algo == 'Linear':
                            cnt["Linear"] += 1
                            if cnt["Linear"] % no == 0:
                                os.system('echo -n "0<CODESPLIT>Linear Search<CODESPLIT>" >> batch_0.txt')
                                cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                                os.system(cmd)
                                continue
                            os.system('echo -n "0<CODESPLIT>Linear Search<CODESPLIT>" >> train.txt')
                        elif algo == 'Binary':
                            cnt["Binary"] += 1
                            if cnt["Binary"] % no == 0:
                                os.system('echo -n "1<CODESPLIT>Binary Search<CODESPLIT>" >> batch_0.txt')
                                cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                                os.system(cmd)
                                continue
                            os.system('echo -n "1<CODESPLIT>Binary Search<CODESPLIT>" >> train.txt')
                        elif algo == 'BFS':
                            cnt["BFS"] += 1
                            if cnt["BFS"] % no == 0:
                                os.system('echo -n "2<CODESPLIT>BFS Search<CODESPLIT>" >> batch_0.txt')
                                cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                                os.system(cmd)
                                continue
                            os.system('echo -n "2<CODESPLIT>BFS Search<CODESPLIT>" >> train.txt')
                        elif algo == 'DFS':
                            cnt["DFS"] += 1
                            if cnt["DFS"] % no  == 0:
                                os.system('echo -n "3<CODESPLIT>DFS Search<CODESPLIT>" >> batch_0.txt')
                                cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                                os.system(cmd)
                                continue
                            os.system('echo -n "3<CODESPLIT>DFS Search<CODESPLIT>" >> train.txt')

                        cmd = 'python tokenizer.py ' + file_path + '>> train.txt'
                        os.system(cmd)

