import os
import shutil

for dir in os.listdir('Filtered-Data'):
    for file in os.listdir('Filtered-Data/'+dir):
        print(file)
        if file.endswith('.py'):
            os.system('python3 pycfg-0.1/pycfg/pycfg.py Filtered-Data/'+dir+'/'+file + ' -d > '+ 'Dot-Data/'+ dir +'/' +file.split('.')[0]+'.dot')
            