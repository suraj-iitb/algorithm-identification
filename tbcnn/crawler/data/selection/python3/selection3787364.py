def bubbleSort(A,N):
    global cnt
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j]<A[minj]:
                minj = j
        if i!=minj:cnt+=1
        A[i],A[minj] = A[minj],A[i]
N = int(input())
A = list(map(int,input().split()))
cnt = 0
bubbleSort(A,N)
print(*A)
print(cnt)
