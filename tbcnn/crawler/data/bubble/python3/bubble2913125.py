N = int(input())
A = list(map(int, input().split()))

flag = True
counter = 0
while flag:
    flag = False
    for i in range(N-1, 0, -1):
        if A[i-1] > A[i]:
            A[i], A[i-1] = A[i-1], A[i]
            flag = True
            counter += 1

print(' '.join(map(str, A)))
print(counter)

