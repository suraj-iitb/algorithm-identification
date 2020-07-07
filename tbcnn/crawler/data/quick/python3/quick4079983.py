import copy

def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if int(A[j][2:]) <= int(x[2:]):
            i = i + 1
            y = A[i]
            A[i] = A[j]
            A[j] = y
    z = A[i+1]
    A[i+1] = A[r]
    A[r] = z
    return i + 1

def quickSort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quickSort(A, p, q-1)
        quickSort(A, q+1, r)

n = int(input())
A = []
for i in range(n):
    A.append(str(input()))

B = copy.deepcopy(A)
B.sort(key = lambda x: int(x[2:]))

quickSort(A, 0, n-1)

if A == B:
    print('Stable')
else:
    print('Not stable')

for i in range(n):
    print(A[i])
