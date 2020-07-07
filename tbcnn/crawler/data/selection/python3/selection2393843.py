N = int(input())
A = [int(A) for A in input().split()]
cnt = 0
for i in range(N):
    A_min = i
    for j in range(i, N):
        if A[A_min] > A[j]:
            A_min = j
    if i != A_min:
        t = A[i]
        A[i] = A[A_min]
        A[A_min] = t
        cnt += 1

for i in range(N):
    if i == N - 1:
        print(A[i])
    else:
        print("{}".format(A[i]), end=' ')

print(cnt)
