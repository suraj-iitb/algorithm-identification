import os
from subprocess import Popen, PIPE
import subprocess
import time

os.system("g++ -o quick quick.cpp")

n_list = [10, 100, 1000, 10000, 100000]

for n in n_list:
    f = open('Results/quick/tau+delta'+str(n), 'w')

    for t in range(0, 100000):
        start = time.time()  

        subprocess.Popen([os.path.join(os.getcwd(), 'quick')],
            stdin=open('../complexity-analysis/Input/input-'+str(n)),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            shell=True)

        end = time.time()
        diff = end - start
        f.write(str(diff) + '\n')

    f.close()