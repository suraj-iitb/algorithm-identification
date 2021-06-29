import os

no = 6
cnt = {"Bubble": 0, "Insertion": 0, "Selection": 0, "Counting": 0, "Merge": 0, "Quick": 0}
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
                    if algo == 'Bubble':
                        f1.write(str(count)+"\t0\n")
                        f2.write(str(count)+"\t0\n")
                        f3.write(str(count)+"\t0\n")
                        cnt["Bubble"] += 1
                        if cnt["Bubble"] % no == 0:
                            os.system('echo -n "0<CODESPLIT>Bubble Sort<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "0<CODESPLIT>Bubble Sort<CODESPLIT>" >> data.txt')
                    elif algo == 'Insertion':
                        f1.write(str(count)+"\t1\n")
                        f2.write(str(count)+"\t1\n")
                        f3.write(str(count)+"\t1\n")
                        cnt["Insertion"] += 1
                        if cnt["Insertion"] % no == 0:
                            os.system('echo -n "1<CODESPLIT>Insertion Sort<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "1<CODESPLIT>Insertion Sort<CODESPLIT>" >> data.txt')
                    elif algo == 'Selection':
                        f1.write(str(count)+"\t2\n")
                        f2.write(str(count)+"\t2\n")
                        f3.write(str(count)+"\t2\n")
                        cnt["Selection"] += 1
                        if cnt["Selection"] % no == 0:
                            os.system('echo -n "2<CODESPLIT>Selection Sort<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "2<CODESPLIT>Selection Sort<CODESPLIT>" >> data.txt')
                    elif algo == 'Counting':
                        f1.write(str(count)+"\t3\n")
                        f2.write(str(count)+"\t3\n")
                        f3.write(str(count)+"\t3\n")
                        cnt["Counting"] += 1
                        if cnt["Counting"] % no  == 0:
                            os.system('echo -n "3<CODESPLIT>Counting Sort<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "3<CODESPLIT>Counting Sort<CODESPLIT>" >> data.txt')
                    elif algo == 'Merge':
                        f1.write(str(count)+"\t4\n")
                        f2.write(str(count)+"\t4\n")
                        f3.write(str(count)+"\t4\n")
                        cnt["Merge"] += 1
                        if cnt["Merge"] % no == 0:
                            os.system('echo -n "4<CODESPLIT>Merge Sort<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "4<CODESPLIT>Merge Sort<CODESPLIT>" >> data.txt')
                    elif algo == 'Quick':
                        f1.write(str(count)+"\t5\n")
                        f2.write(str(count)+"\t5\n")
                        f3.write(str(count)+"\t5\n")
                        cnt["Quick"] += 1
                        if cnt["Quick"] % no == 0:
                            os.system('echo -n "5<CODESPLIT>Quick Sort<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "5<CODESPLIT>Quick Sort<CODESPLIT>" >> data.txt')

                    cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                    os.system(cmd)
                    count += 1
f1.close()
f2.close()
f3.close()