import math
n = int(input())
*S, = map(int, input().split())
c = 0

def marge(A, p, q, r):
    # n1 = q - p + 1 # qの要素に関しても加算する必要がある。
    # n2 = r - q
    L, R = A[p: q], A[q: r]
    global c
    L.append(int(10E10))
    R.append(int(10E10))

    i, j = 0, 0
    for k in range(p, r):
        c = c + 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1

def marge_sort(A, p, r):
    if p + 1 < r:
        q = math.ceil((p + r) / 2)
        marge_sort(A, p, q)
        marge_sort(A, q, r)
        marge(A, p, q, r)

marge_sort(S, 0, len(S))
print(' '.join(map(str, S)))
print(c)
