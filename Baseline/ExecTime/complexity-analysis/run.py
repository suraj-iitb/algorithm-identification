import os
from subprocess import Popen, PIPE
import subprocess

# os.system("g++ -o heap_sort merge-sort.cpp")
# os.system("g++ -o merge_sort heap-sort.cpp")
os.system("g++ -o bubble_sort bubble-sort.cpp")
os.system("g++ -o insertion_sort insertion-sort.cpp")

# n_list = [10,100,1000, 5000,10000,20000,30000,40000,50000,60000,70000, 80000,90000, 100000]

n_list = [10,100,500]
for n in range(1000, 100001, 1000):
    n_list.append(n)

for n in n_list:
     subprocess.Popen([os.path.join(os.getcwd(), 'bubble_sort')],
            stdin=open('Input/input-'+str(n)),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            shell=True)
     subprocess.Popen([os.path.join(os.getcwd(), 'insertion_sort')],
            stdin=open('Input/input-'+str(n)),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            shell=True)
