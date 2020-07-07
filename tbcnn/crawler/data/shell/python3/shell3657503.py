def insertionSort(a,n,g):
  global count
  for i in range(g,n):
    v = a[i]
    j = i - g
    while j >= 0 and a[j] > v:
      a[j+g] = a[j]
      j = j - g
      count += 1
    a[j+g] = v

import sys
n = int(input())
a = list(map(int,sys.stdin))
count = 0
g = [88573,29524,9841,3280,1093,364,121,40,13,4,1]
g = [i for i in g if i <= n]
for i in range(len(g)):
  insertionSort(a,n,g[i])
print(len(g))
print(' '.join(map(str,g)))
print(count)
for i in range(n):
  print(a[i])
