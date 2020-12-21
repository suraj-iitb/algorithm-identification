import os

# for dir1 in os.listdir('Data/'):
#     if not '.zip' in dir1:
dir1 = 'CS 335-2020-1-Graded CS337+335 Assignment 4-15668'
for dir2 in os.listdir('Data/'+dir1):
    # count = 0
    for z in os.listdir('Data/'+dir1+'/'+dir2):
        # count += 1
        # if '.zip' in z:
        #     name = '"Data/'+dir1+'/'+dir2+'/"'
        #     print(name)
        #     os.system('cd ' + name + '&& unzip ' + z)
        if not '.zip' in z:
            if z == '__MACOSX':
                # for z1 in os.listdir('Data/'+dir1+'/'+dir2+'/__MACOSX'):
                #     name = '"Data/'+dir1+'/'+dir2+'/__MACOSX/'+z1+'/._p2.py"'
                #     temp = z1
                continue
            else:        
                name = '"Data/'+dir1+'/'+dir2+'/'+z+'/kmeans.py"'
                temp = z
            print('cp ' + name + ' Filtered-Data/kmeans/'+ temp + '.py')
            os.system('cp ' + name + ' Filtered-Data/kmeans/'+ temp + '.py')
        #         break
        #     break
        # break