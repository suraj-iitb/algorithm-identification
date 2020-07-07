def partition(A, p, r):
    x = A[r][1]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1


def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)


n = int(input())
A = [(t[0], int(t[1]), i) for t, i in [(input().split(), i) for i in range(n)]]
quicksort(A, 0, n-1)
notstable = any([True for i in range(1, n) if A[i][1] == A[i-1][1] and A[i][2] < A[i-1][2]])
print("Not stable" if notstable else "Stable")
for v in A:
    print(f"{v[0]} {v[1]}")
