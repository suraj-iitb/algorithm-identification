# Selection Sort
N = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(N):
    min_idx = i
    # i番目以降での最小を探す
    for j in range(i, N):
        if A[j] < A[min_idx]:
            min_idx = j

    if i != min_idx:
        A[i], A[min_idx] = A[min_idx], A[i]
        cnt += 1

print(*A)
print(cnt)

