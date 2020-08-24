import numpy as np 
from scipy.optimize import curve_fit 
from matplotlib import pyplot as plt 

x1 = []
y1 = []

with open('time_bubble.txt') as b:
    for line in b:
        line = line.strip().split(' ')
        x1.append(int(line[0]))
        y1.append(float(line[1]))

x2 = []
y2 = []

with open('time_insertion.txt') as i:
    for line in i:
        line = line.strip().split(' ')
        x2.append(int(line[0]))
        y2.append(float(line[1]))

x3 = []
y3 = []

with open('time_merge.txt') as m:
    for line in m:
        line = line.strip().split(' ')
        x3.append(int(line[0]))
        y3.append(float(line[1]))

x4 = []
y4 = []

with open('time_heap.txt') as h:
    for line in h:
        line = line.strip().split(' ')
        x4.append(int(line[0]))
        y4.append(float(line[1]))
 

def test(x, c1, c2, c3, c4, c5): 
    return c1*np.square(x) + c2*x*np.log(x) + c3*x + c4*np.log(x) + c5

param_b, _ = curve_fit(test, x1, y1)
param_i, _ = curve_fit(test, x2, y2) 
param_m, _ = curve_fit(test, x3, y3)
param_h, _ = curve_fit(test, x4, y4) 

print("Bubble sort coefficients:") 
print(param_b) 
print("Insertion sort coefficients:") 
print(param_i) 
print("Merge sort coefficients:") 
print(param_m) 
print("Heap sort coefficients:") 
print(param_h) 

ans_b = param_b[1]*(x1*(np.log(x1))) + param_b[2]*np.float_(x1) + param_b[3]*(np.log(x1)) + param_b[4] +param_b[0]*(np.square(x1))
ans_i = param_i[1]*(x2*(np.log(x2))) + param_i[2]*np.float_(x2) + param_i[3]*(np.log(x2)) + param_i[4] +param_i[0]*(np.square(x2))
ans_m = param_m[1]*(x1*(np.log(x1))) + param_m[2]*np.float_(x1) + param_m[3]*(np.log(x1)) + param_m[4] + param_m[0]*(np.square(x1))
ans_h = param_h[1]*(x2*(np.log(x2))) + param_h[2]*np.float_(x2) + param_h[3]*(np.log(x2)) + param_h[4] + param_h[0]*(np.square(x2)) 

# plt.ylim(0, 2)
plt.plot(x1, ans_b, '-', color ='red', label ="Bubble sort") 
plt.plot(x2, ans_i, '-', color ='blue', label ="Insertion sort") 
plt.plot(x3, ans_m, '-', color ='yellow', label ="Merge sort") 
plt.plot(x4, ans_h, '-', color ='orange', label ="Heap sort") 
# plt.plot(x1, 0.000000002*(np.square(x1)), '-', color ='green', label ="coeff*n*n") 
# plt.plot(x1, 0.00000004*(x1*(np.log(x1))), '-', color ='grey', label ="coeff*n*log(n)") 
plt.legend() 
plt.savefig('exec-all.png')
