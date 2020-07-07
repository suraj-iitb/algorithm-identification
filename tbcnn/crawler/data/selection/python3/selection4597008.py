# coding: utf-8
# Your code here!

def selectionSort(A,N):
    cnt=0
    for i in range(N):
        minj=i
        for j in range(i,N):
            if A[j]<A[minj]:
                minj=j
        if i != minj:
            cnt+=1
        A[i],A[minj]=A[minj],A[i]
    return(cnt)
a=int(input())
b=list(map(int,input().split(" ")))
c=selectionSort(b,a)
print(" ".join(list(map(str,b))),c,sep="\n")
