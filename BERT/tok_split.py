import os

no = 6
cnt = {"Bubble": 0, "Insertion": 0, "Selection": 0, "Counting": 0, "Merge": 0, "Quick": 0}
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
                    if algo == 'Bubble':
                        cnt["Bubble"] += 1
                        if cnt["Bubble"] % no == 0:
                            os.system('echo -n "0<CODESPLIT>Bubble Sort<CODESPLIT>" >> batch_0.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "0<CODESPLIT>Bubble Sort<CODESPLIT>" >> train.txt')
                    elif algo == 'Insertion':
                        cnt["Insertion"] += 1
                        if cnt["Insertion"] % no == 0:
                            os.system('echo -n "1<CODESPLIT>Insertion Sort<CODESPLIT>" >> batch_0.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "1<CODESPLIT>Insertion Sort<CODESPLIT>" >> train.txt')
                    elif algo == 'Selection':
                        cnt["Selection"] += 1
                        if cnt["Selection"] % no == 0:
                            os.system('echo -n "2<CODESPLIT>Selection Sort<CODESPLIT>" >> batch_0.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "2<CODESPLIT>Selection Sort<CODESPLIT>" >> train.txt')
                    elif algo == 'Counting':
                        cnt["Counting"] += 1
                        if cnt["Counting"] % no  == 0:
                            os.system('echo -n "3<CODESPLIT>Counting Sort<CODESPLIT>" >> batch_0.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "3<CODESPLIT>Counting Sort<CODESPLIT>" >> train.txt')
                    elif algo == 'Merge':
                        cnt["Merge"] += 1
                        if cnt["Merge"] % no == 0:
                            os.system('echo -n "4<CODESPLIT>Merge Sort<CODESPLIT>" >> batch_0.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "4<CODESPLIT>Merge Sort<CODESPLIT>" >> train.txt')
                    elif algo == 'Quick':
                        cnt["Quick"] += 1
                        if cnt["Quick"] % no == 0:
                            os.system('echo -n "5<CODESPLIT>Quick Sort<CODESPLIT>" >> batch_0.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "5<CODESPLIT>Quick Sort<CODESPLIT>" >> train.txt')

                    cmd = 'python tokenizer.py ' + file_path + '>> train.txt'
                    os.system(cmd)
