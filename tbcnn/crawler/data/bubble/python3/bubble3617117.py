def bubbleSort(A,N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                flag = 1
                count += 1
    return A,count

N = int(input())
A = list(map(int, input().split()))
A,count = bubbleSort(A,N)
print(" ".join(map(str,A)))
print("%d"%(count))

