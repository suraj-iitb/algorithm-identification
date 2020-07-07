N = int(input())
A = [int(i) for i in input().split()]

count = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j

    if i != minj:
        A[i], A[minj] = A[minj], A[i]
        count += 1

for i in range(N):
    print(A[i], end='')
    if i != N - 1:
        print(' ', end='')
print('')

print(count)
