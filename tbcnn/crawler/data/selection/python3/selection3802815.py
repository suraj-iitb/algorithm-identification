r = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(r):
    min_j = i
    for j in range(i+1, r):
        if A[j] < A[min_j]:
            min_j = j
    if min_j > i:
        A[min_j], A[i] = A[i], A[min_j]
        cnt+=1
print(" ".join(map(str, A)))
print(cnt)
