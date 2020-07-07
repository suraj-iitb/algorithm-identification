N = int(input())
A = [int(i) for i in input().split()]

flag = True

count = 0
while flag:
    flag = False
    for i in range(1, N):
        if A[i] < A[i - 1]:
            A[i], A[i - 1] = A[i - 1], A[i]
            flag = True
            count += 1

for i in range(N):
    print(A[i], end='')
    if i != N - 1:
        print(' ', end='')
print('')

print(count)

