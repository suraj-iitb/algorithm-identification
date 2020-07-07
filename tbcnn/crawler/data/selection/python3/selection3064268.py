N = int(input())
A = list(map(int, input().split()))

# selectionSortの処理
count = 0
for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    A[i], A[minj] = A[minj], A[i]
    if i != minj:
        count += 1
print(*A)
print(count)

