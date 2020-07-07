def partition(A, p, r):
    x = A[r][1]
    i = p - 1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

def quick_sort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        # 左半分
        quick_sort(A, p, q - 1)
        # 右半分
        quick_sort(A, q + 1, r)
n = int(input())
A = []
for _ in range(n):
    a, b = input().split()
    A.append((a, int(b)))
ind = dict((e, i) for i, e in enumerate(A))
quick_sort(A, 0, n - 1)
for i in range(n - 1):
    if A[i][1] == A[i + 1][1]:
        if ind[A[i]] > ind[A[i + 1]]:
            print('Not stable')
            break
else:
    print('Stable')
for i in A:
    print(*i)
