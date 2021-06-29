import os

no = 6
cnt = {"All": 0, "SS": 0}
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
                    if algo == 'All':
                        f1.write(str(count)+"\t0\n")
                        f2.write(str(count)+"\t0\n")
                        f3.write(str(count)+"\t0\n")
                        cnt["All"] += 1
                        if cnt["All"] % no == 0:
                            os.system('echo -n "0<CODESPLIT>All pair shortest path<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "0<CODESPLIT>All pair shortest path<CODESPLIT>" >> data.txt')
                    elif algo == 'SS':
                        f1.write(str(count)+"\t1\n")
                        f2.write(str(count)+"\t1\n")
                        f3.write(str(count)+"\t1\n")
                        cnt["SS"] += 1
                        if cnt["SS"] % no == 0:
                            os.system('echo -n "1<CODESPLIT>Single Source shortest path<CODESPLIT>" >> data.txt')
                            cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                            os.system(cmd)
                            continue
                        os.system('echo -n "1<CODESPLIT>Single Source shortest path<CODESPLIT>" >> data.txt')
                        
                    cmd = 'python tokenizer.py ' + file_path + '>> data.txt'
                    os.system(cmd)
                    count += 1
f1.close()
f2.close()
f3.close()