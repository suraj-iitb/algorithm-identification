def CountingSort(A, k):
    n = len(A)
    C = [0for i in range(k+1)]
    #C[i] に i の出現数を記録する
    for i in range(n):
        C[A[i]] += 1
    #C[i] に i 以下の数の出現数を記録する
    for i in range(1,k+1):
        C[i] += C[i-1]
    
    B = [0for i in range(n)]  ##출력 배열 (出力配列)
    for j in range(n):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
    return B
        
n = int(input())
A = list(map(int, input().split()))
k = max(A)
print(*CountingSort(A,k))

