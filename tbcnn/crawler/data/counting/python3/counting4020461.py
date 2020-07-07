def countingsort(A, k):
    C = [0 for _ in range(k)]
    ret = [-1 for _ in A]
    for a in A:
        C[a] += 1
    for i in range(k - 1):
        C[i + 1] += C[i]
    for a in reversed(A):
        ret[C[a]-1] = a
        C[a] -= 1
    return ret


_, *A = map(int, open(0).read().split())
A = countingsort(A, max(A) + 1)
print(' '.join(map(str, A)))
