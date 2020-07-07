def CountingSort(A,B,k):
    
    C = [0]*10001
    """
    for i in range(k+1):
        C[i] = 0
    """
    
    for i in A:
        C[i] += 1
    
    for i in range(1,k+1):
        C[i] += C[i-1]

    for j in reversed(range(len(A))):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1

n = int(input())
a = tuple(map(int,input().split()))

b = [0 for i in range(n)]
CountingSort(a,b,max(a))
print(*b)
