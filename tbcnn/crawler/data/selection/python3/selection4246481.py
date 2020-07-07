n = int(input())
A = list(map(int, input().split()))

count = 0
for i in range(n):
    minj = i
    for j in range(i + 1, n):
        if (A[minj] > A[j]):
            minj = j
    if (i != minj):
        A[i], A[minj] = A[minj], A[i]
        count += 1

print(' '.join(map(str, A)))
print(count)

