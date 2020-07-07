N = int(input())
A = [int(x) for x in input().split()]

flag = 1
count = 0
while flag:
    flag = 0
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            count += 1
            flag = 1

for _ in range(N):
    if _ == N-1:
        print(A[_], sep=' ',end='')
    else:
        print(A[_], sep='',end=' ')
print()
print(count)
