# Importing the required modules 
import os 
import sys 
import pandas as pd 
from bs4 import BeautifulSoup 

sys.setrecursionlimit(10000)

path = '../../Results/Raw/Dump/All/20/online-report.html'
op = 'Results/all/20/20.csv'

data = [] 

soup = BeautifulSoup(open(path),'html.parser') 
header = soup.find_all("table")[0].find("tr")
print(header)
for items in header: 
	try: 
		data.append(items.get_text()) 
	except: 
		continue

data = data[0].split('\n')[1:-1]
print(len(data))
print(data)

new_data = []
for i in range(1,len(data)+1):
    if i%3 != 0:
        new_data.append(data[i-1])
print(len(new_data))
print(new_data)
for d in new_data:
    print(d)

with open(op, 'w') as f:
    for i in range(0, len(new_data), 2):
        a = new_data[i].split('(')
        b = new_data[i+1].split('(')
        f.write(a[0].strip().split('/')[-1] + ',' + a[1][:-2] + ',' + b[0].strip().split('/')[-1] + ',' + b[1][:-2] + '\n')
