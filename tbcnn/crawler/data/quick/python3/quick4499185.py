n = int(input())
A = []
for i in range(n):
    mark,number = map(str,input().split())
    A.append((mark, int(number), i))

def partition(A, p, r):
    x = A[r][1]
    i = p - 1
    for j in range(p,r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return A, i + 1

def quickSort(A, p, r):
    if p < r:
        A, q = partition(A, p, r)
        quickSort(A, p, q-1)
        quickSort(A, q+1, r)
    return A

A = quickSort(A, 0, n-1)

is_stable = True
for i in range(1, len(A)):
    if(A[i-1][1] == A[i][1]) and (A[i-1][2] > A[i][2]):
        is_stable = False
        break
print('Stable') if is_stable else print('Not stable')
for i in range(len(A)):
    print("{0} {1}".format(A[i][0], A[i][1]))
