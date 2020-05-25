import os
from subprocess import Popen, PIPE
import subprocess

os.system("g++ -o heap_sort merge-sort.cpp")
os.system("g++ -o merge_sort heap-sort.cpp")

steps = 1
n_list = []

for _ in range(1, 7):
    steps = steps * 10
    n_list.append(steps)

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
