import os

no = 10
cnt = {"All": 0, "SS": 0}
with open('log.txt', 'w') as f:
    for algo in os.listdir('Data_Dump/Path/'):
        algo_path = os.path.join('Data_Dump/Path/', algo)
        for lang in os.listdir(algo_path):
            if lang == "C":
                lang_path = os.path.join(algo_path, lang)
                for file in os.listdir(lang_path):
                    if not file.endswith('.txt'):
                        file_path = os.path.join(lang_path, file)
                        print(file_path)
                        f.write(file_path+"\n")
                        if algo == 'All':
                            cnt["All"] += 1
                            if cnt["All"] % no == 0:
                                os.system('echo -n "0<CODESPLIT>Single Source Shortest Path<CODESPLIT>" >> batch_0.txt')
                                cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                                os.system(cmd)
                                continue
                            os.system('echo -n "0<CODESPLIT>Single Source Shortest Path<CODESPLIT>" >> train.txt')
                        elif algo == 'SS':
                            cnt["SS"] += 1
                            if cnt["SS"] % no == 0:
                                os.system('echo -n "1<CODESPLIT>All Pair Source Shortest Path<CODESPLIT>" >> batch_0.txt')
                                cmd = 'python tokenizer.py ' + file_path + '>> batch_0.txt'
                                os.system(cmd)
                                continue
                            os.system('echo -n "1<CODESPLIT>All Pair Source Shortest Path<CODESPLIT>" >> train.txt')

                        cmd = 'python tokenizer.py ' + file_path + '>> train.txt'
                        os.system(cmd)

