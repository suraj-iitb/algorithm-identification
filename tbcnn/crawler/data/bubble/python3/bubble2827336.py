N = int(input())
A = [int(x) for x in input().split()]

flag = True
count = 0

while flag:
    flag = False
    for i in range(1, N)[::-1]:
        if A[i] < A[i-1]:
            A[i], A[i-1] = A[i-1], A[i]
            flag = True
            count += 1
print(' '.join(map(str, A)))
print(count)

