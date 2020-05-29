import numpy as np 
from scipy.optimize import curve_fit 
from matplotlib import pyplot as plt 

x1 = []
y1 = []

with open('time_merge.txt') as m:
    for line in m:
        line = line.strip().split(' ')
        x1.append(int(line[0]))
        y1.append(float(line[1]))

x2 = []
y2 = []

with open('time_heap.txt') as h:
    for line in h:
        line = line.strip().split(' ')
        x2.append(int(line[0]))
        y2.append(float(line[1]))
 
def test(x, c1, c2, c3, c4, c5): 
    return c1*np.square(x) + c2*x*np.log(x) + c3*x + c4*np.log(x) + c5

param_m, _ = curve_fit(test, x1, y1)
param_h, _ = curve_fit(test, x2, y2) 

print("Merge sort coefficients:") 
print(param_m) 
print("Heap sort coefficients:") 
print(param_h) 

ans_m = param_m[0]*(np.square(x1)) + param_m[1]*(x1*(np.log(x1))) + param_m[2]*np.float_(x1) + param_m[3]*(np.log(x1)) + param_m[4]
ans_h = param_h[0]*(np.square(x2)) + param_h[1]*(x2*(np.log(x2))) + param_h[2]*np.float_(x2) + param_h[3]*(np.log(x2)) + param_h[4]

plt.plot(x1, ans_m, '-', color ='red', label ="Merge sort") 
plt.plot(x2, ans_h, '-', color ='blue', label ="Heap sort") 
plt.legend() 
plt.savefig('exec.png')
