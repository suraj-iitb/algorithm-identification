N = int(input())
A = list(map(int, input().split()))

count = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        A[i], A[minj] = A[minj], A[i]
        count += 1

for k in range(N):
        if k > 0:
            print(' ', end='')
        print(A[k], end='')

print('')
print(count)
