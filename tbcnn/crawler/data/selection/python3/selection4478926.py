N = int(input())
A = list(map(int,input().split()))
count =0
for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        dummy = A[i]
        A[i] = A[minj]
        A[minj] = dummy
        count +=1
for i in range(N-1):
    print(f"{A[i]}",end=" ")
print(f"{A[N-1]}\n{count}")
