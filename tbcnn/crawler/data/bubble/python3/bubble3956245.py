N = int(input())
A = [int(i) for i in input().split()]
counter = 0
flag = True

while flag:
    flag = False
    i = 0
    for j in range(N-1, i, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            counter += 1
            flag = True
    i += 1
A = [str(i) for i in A]
print(' '.join(A))
print(counter)

