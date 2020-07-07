N = int(input())
A = list(map(int,input().split()))

def pr(list):
    n = len(list)
    for i in range(n):
        if i < n-1:
            print(list[i],end=" ")
        else:
            print(list[i],end="\n")

def sort():
    swap = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            temp = A[i]
            A[i] = A[minj]
            A[minj] = temp
            swap += 1
    pr(A)
    print(swap)

sort()

