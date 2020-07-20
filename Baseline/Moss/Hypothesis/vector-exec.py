import os
from subprocess import Popen, PIPE
import subprocess
import time

os.system("g++ -o bubble_sort bubble-sort.cpp")
os.system("g++ -o insertion_sort insertion-sort.cpp")

n_list = [500]

f = open('tau+delta.txt', 'w')
for t in range(0,100):
    for n in n_list:
        start = time.time()  

        subprocess.Popen([os.path.join(os.getcwd(), 'bubble_sort')],
            stdin=open('Input/input-'+str(n)),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            shell=True)

        end = time.time()

        f.write(str(end-start) + '\n')

f.close()
    # os.system('./bubble_sort < Input/input-500')