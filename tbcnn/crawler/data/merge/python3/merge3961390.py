cp = 0
def m(L,R):
    global cp
    j = 0
    for l in L:
        while j < len(R) and R[j] < l:
            yield R[j]
            j += 1
        yield l
    while j < len(R):
        yield R[j]
        j += 1
    cp += len(L) + len(R)
def merge(A):
    global cp
    if len(A) == 1:
        return A
    if len(A) == 2:
        cp += 2
        a, b = A
        return A if a < b else (b, a)
    mid = len(A) // 2
    A[:] = m(merge(A[:mid]), merge(A[mid:]))
    return A
n=int(input())
A=[int(i) for i in input().rstrip().split(" ")]
B = merge(A)
print(*B)
print(cp)
