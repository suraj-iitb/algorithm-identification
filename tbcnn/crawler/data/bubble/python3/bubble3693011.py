def hyoji(l):
    for i in range(len(l)):
        if i != len(l) - 1:
            print(l[i], end = ' ')
        else:
            print(l[i])

n = int(input())
A = list(map(int, input().split()))

c = 0
for j in range(len(A)):
    for k in range(len(A) - 1, j, -1):
        if A[k] < A[k - 1]:
            A[k], A[k - 1] = A[k-1], A[k]
            c += 1
hyoji(A)
print(c)
