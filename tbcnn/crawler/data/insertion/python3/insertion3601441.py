N = int(input())
A = list(map(int,input().split()))

def sort(N,A):
    for i in range(N):
        v = A[i]
        j = i-1
        while(j >= 0 and A[j] > v):
            A[j+1] = A[j]
            j -= 1
            A[j+1] = v
        pr(A)

def pr(list):
    n = len(list)
    for i in range(n):
        if i < n-1:
            print(list[i],end=" ")
        else:
            print(list[i],end="\n")

sort(N,A)

