def insort(n,A):
    for i in range(n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        L=[str(a) for a in A]
        L=" ".join(L)
        print(L)

n = int(input())
A = list(map(int,input().split()))

insort(n,A)

