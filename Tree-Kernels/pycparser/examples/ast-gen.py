import os

data = "/home/suraj/Data_Dump"
with open('log.txt', 'w') as f:
    for algo in os.listdir(data):
        algo_path = os.path.join(data, algo)
        for lang in os.listdir(algo_path):
            if lang == "C":
                lang_path = os.path.join(algo_path, lang, 'Code')
                for file in os.listdir(lang_path):
                    file_path = os.path.join(lang_path, file)
                    print(file_path)
                    f.write(file_path+"\n")
                    # os.system("python3 examples/my_parser.py " + file + " >> ../Data1/" + algo.lower() + ".ast")
                            