N = int(input())
A = list(map(int, input().split()))

flag = 1
count = 0
while flag:
    flag = 0
    for i in range(0, N-1, 1):
        if A[i] > A[i+1]:
            A[i], A[i+1] = A[i+1], A[i]
            flag = 1
            count = count + 1

A_str = map(str, A)
print(' '.join(A_str))
print(count)

