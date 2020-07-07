# coding: utf-8
# Here your code !
S = int(input())
N = list(map(int,input().split(" ")))


def seleSort(n,s):
    c =0
    for i in range(s):
        minj = i
        for j in range(i+1,s):
            if n[j]<n[minj]:
                minj = j
                
        n[i],n[minj]=n[minj],n[i]
        if i!= minj:
            c+=1
    print(" ".join(list(map(str,n))))
    print(c)
        
        
seleSort(N,S)
