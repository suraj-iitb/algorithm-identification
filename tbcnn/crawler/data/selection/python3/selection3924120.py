import sys
input = sys.stdin.readline

N=int(input())
A = list(map(int, input().split()))

def SelectionSort(N):
    count=0
    for i in range(N):
        minj=i
        for j in range(i,N):
            if A[j]<A[minj]:
                minj=j
        A[i],A[minj]=A[minj],A[i]
        if i!=minj:
            count+=1
    print(*A)
    print(count)
SelectionSort(N)
