n = int(input())
A = list(map(int,input().split()))
for i, a in enumerate(A):
    temp = a
    i -= 1
    while i >= 0 and A[i] >temp:
        A[i+1] = A[i]
        A[i] = temp
        i -= 1
    L=[str(a) for a in A]   
    p = ' '.join(L)
    print(p)
