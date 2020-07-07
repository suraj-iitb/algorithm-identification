def CountingSort(A, B, n, k):
    C = [0]*(k+1)
    
    # C[i] に i の出現数を記録する
    for j in range(n):
        C[A[j]]+=1
        
    #C[i] に i 以下の数の出現数を記録する
    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
        
    for j in range(n):
        B[C[A[j]]-1] = A[j]
        C[A[j]]-=1

if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))
    B = A[:]
    k = max(A)
    CountingSort(A, B, n, k)
    print(' '.join(map(str, B)))
