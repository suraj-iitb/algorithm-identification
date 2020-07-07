def hyoji(l):
    for i in range(len(l)):
        if i != len(l)-1:
            print(l[i], end = ' ')
        else:
            print(l[i])

n = int(input())
A = list(map(int, input().split()))

c = 0
for j in range(len(A)):
    min_n = j
    for k in range(j + 1, len(A)):
        if A[k] < A[min_n]:
            min_n = k
    if min_n != j:
        A[j], A[min_n] = A[min_n], A[j]
        c += 1
hyoji(A)
print(c)
