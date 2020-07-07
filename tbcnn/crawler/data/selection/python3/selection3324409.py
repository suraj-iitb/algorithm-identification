from sys import stdin

N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]

count = 0
for i in range(N):
    minj = i
    for j in range(i+1, N):
        if A[j] < A[minj]:
            minj = j

    if i != minj:
        A[i], A[minj] = A[minj], A[i]
        count += 1

print(*A)
print(count)
