import os
import shutil

for dir in os.listdir('Dot-Data'):
    for file in os.listdir('Dot-Data/'+dir):
        print(file)
        if file.endswith('.dot'):
            # print('graph-easy Dot-Data/'+dir+'/'+file + ' --graphml --out XML-Data/'+ dir +'/'  + file.split('.')[0] + '.graphml')
            os.system('graph-easy Dot-Data/'+dir+'/'+file + ' --graphml --out XML-Data/'+ dir +'/'  + file.split('.')[0] + '.graphml')
    #         break
    # break    