import sys
input = sys.stdin.readline

N=int(input())
A = list(map(int, input().split()))

def bubbleSort(N):
    Flag=True
    count=0
    while Flag:
        Flag=False
        for j in reversed(range(1,N)):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                Flag=True
                count+=1
    print(*A)
    print(count)
bubbleSort(N)
