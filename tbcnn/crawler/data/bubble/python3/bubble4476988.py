N = int(input())
A = list(map(int,input().split()))
flag = 1
count = 0
while flag:
    flag = 0
    for j in range(1,N):
        if A[N-j] < A[N-j-1]:
            dummy = A[N-j]
            A[N-j] = A[N-j-1]
            A[N-j-1] = dummy
            flag = 1
            count += 1
for i in range(N-1):
    print(A[i],end=" ")
print(f"{A[N-1]}\n{count}")
