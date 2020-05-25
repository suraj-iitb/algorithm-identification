import os
from subprocess import Popen, PIPE
import subprocess

os.system("g++ -o heap_sort merge-sort.cpp")
os.system("g++ -o merge_sort heap-sort.cpp")

# steps = 1
n_list = [10,100,1000, 5000,10000,20000,30000,40000,50000,60000,70000, 80000,90000, 100000]

# for _ in range(1, 7):
#     steps = steps * 10
#     n_list.append(steps)

for n in n_list:
    subprocess.Popen([os.path.join(os.getcwd(), 'merge_sort')],
           stdin=open('input-'+str(n)),
           stdout=subprocess.PIPE, 
           stderr=subprocess.STDOUT,
           shell=True)
    subprocess.Popen([os.path.join(os.getcwd(), 'heap_sort')],
           stdin=open('input-'+str(n)),
           stdout=subprocess.PIPE, 
           stderr=subprocess.STDOUT,
           shell=True)

for n in n_list:
     subprocess.Popen([os.path.join(os.getcwd(), 'heap_sort')],
            stdin=open('input-'+str(n)),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            shell=True)
     subprocess.Popen([os.path.join(os.getcwd(), 'merge_sort')],
            stdin=open('input-'+str(n)),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            shell=True)
