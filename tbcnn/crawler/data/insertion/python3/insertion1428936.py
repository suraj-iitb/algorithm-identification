#!/usr/bin/env python

def InsertSort(N,A):
    for i in range(1,N):
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j-=1
        A[j+1]=v
        print(*A)


if __name__ == "__main__":
    N=int(input())
    arr=list(map(int,input().split()))
    print(*arr)
    InsertSort(N,arr)
