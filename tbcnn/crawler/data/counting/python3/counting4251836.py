def countingsort(A, k):
    C = [0] * (k+1)
    n = len(A)
    
    for i in A:
        C[i] += 1
        
    for i in range(1, k+1):
        C[i] += C[i-1]
        
    B = [0] * n
    for i in A:
        rank = C[i]
        B[rank-1] = i
        C[i] -= 1
        
    return B
    
n = int(input())
A = [int(i) for i in input().split()]

ans = countingsort(A, 10000)
print(" ".join([str(i) for i in ans]))
