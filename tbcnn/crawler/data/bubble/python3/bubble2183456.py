def bubbleSort(A, N):
    swap = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                swap += 1
                flag = True
    return swap
N = int(input())
A = list(map(int,input().split()))
swap=bubbleSort(A,N)
print(" ".join(map(str,A)))
print (swap)
