def partition(A, p, r):
    x = A[r][1]
    i = p - 1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)


n, *D = open(0).read().split()
n = int(n)
A = [(D[2 * i], int(D[2 * i + 1]), i) for i in range(n)]
quicksort(A, 0, n - 1)
stable = True
for i in range(n-1):
    if A[i][1] == A[i + 1][1] and A[i][2] > A[i + 1][2]:
        stable = False
print('Stable' if stable else 'Not stable')
A = [(a[0], a[1]) for a in A]
print('\n'.join(map(lambda x: ' '.join(map(str, x)), A)))

