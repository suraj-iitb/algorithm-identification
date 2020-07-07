def counting_sort(A, B, k):
    n = len(A)
    C = [0]*(k+1)
    
    # 整数kがAに何回現れるかを数える(n)
    for j in range(n):
        C[A[j]] += 1    
        
    # k以下の整数がAに何回現れるかを数える(k)
    for j in range(1, k+1):
        C[j] = C[j] + C[j-1]        
    
    # Cの情報を利用して並べ替える(n)
    for j in range(n-1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1

n = int(input())
A = list(map(int, input().split() ))
B = [0]*len(A)

counting_sort(A, B, max(A))
print(' '.join(map(str, B)))
