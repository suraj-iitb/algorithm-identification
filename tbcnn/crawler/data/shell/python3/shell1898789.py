import math
import sys

def insertion_sort(a, n, g):
    ct = 0
    for i in range(g,n):
        v = a[i]
        j = i-g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j-g
            ct += 1
        a[j+g] = v
    return ct

n = int(input())
a = list(map(int, sys.stdin.readlines()))
m = 0
b = 0
ct= 0
g = []
while True:
    b = 2.25*b+1
    if b > n:
        break
    g.append(math.ceil(b))
    m += 1
g = g[::-1]

for i in g:
    ct += insertion_sort(a, n, i)

print(m)
print(*g, sep=" ")
print(ct)
print(*a, sep="\n")
