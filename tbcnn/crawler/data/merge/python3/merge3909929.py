import sys
from sys import stdin
input = stdin.readline

inf = float("inf")
cnt = 0
def MS(NL, l, r):
    if l+1 <r:
        m = (l+r)//2
        MS(NL, l, m)
        MS(NL, m, r)
        M(NL, l, m, r)

def M(NL, l, m, r):
    global cnt
    L = NL[l:m]+[inf]
    R = NL[m:r]+[inf]
    i, j = 0, 0
    for k in range(l, r):
        if L[i] >= R[j]:
            NL[k] = R[j]
            j += 1
        else:
            NL[k] = L[i]
            i += 1
    cnt += (r-l)
    
n = int(input())
NL = list(map(int, input().split()))
MS(NL, 0, n)

print(" ".join(list(map(str, NL))))
print(cnt)
