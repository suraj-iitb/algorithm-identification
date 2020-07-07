c = 0
def m(L,R):   
    global c
    j = 0
    for l in L:
        while (j < len(R) and R[j] < l):
            yield R[j]
            j += 1
        yield l
    while (j < len(R)):
        yield R[j]
        j += 1
    c += len(L) + len(R)
    
def merge(A):
    global c
    if len(A) == 1:
        return A
    if len(A) == 2:
        c += 2
        a, b = A
        return A if a < b else (b, a)
    mid = len(A)//2
    A[:] = m(merge(A[:mid]), merge(A[mid:]))
    return A
    
n = int(input())
nlist = list(map(int,input().split()))
A = merge(nlist)  
print(*A)
print(c)
        
