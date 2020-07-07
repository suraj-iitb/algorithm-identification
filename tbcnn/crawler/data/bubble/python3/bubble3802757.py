r = int(input())
A = list(map(int, input().split()))

cnt = 0
for a in A:
    for i in range(r - 1, 0, -1):
        if A[i] < A[i-1]:
            A[i-1], A[i] = A[i], A[i-1]
            cnt+=1
print(" ".join(map(str, A)))
print(cnt)
