n = int(input())
A = list(map(int, input().split()))
cnt = 0

for i in range(n):
    min_j = i
    for j in range(i+1,n):
        if A[j] < A[min_j]:
            min_j = j
    if min_j != i:
        buf = A[i]
        A[i] = A[min_j]
        A[min_j] = buf
        cnt += 1
for k in range(n):
    if k != n-1:
        print(A[k],"",end="")
    else:
        print(A[k])
print(cnt)
