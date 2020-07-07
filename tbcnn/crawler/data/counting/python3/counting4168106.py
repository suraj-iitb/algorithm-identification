def countingSort(A):
    k = max(A)
    n = len(A)
    C = [0 for i in range(k+1)]

    #C[i]にAの要素としてのiの出現数を記録する
    for i in range(n):
        C[A[i]] += 1

    #print(C)

    #C[i]にi以下の数の出現数を記録する
    for i in range(1,k+1):
        C[i] += C[i-1]

    #print(C)

    B = [0 for i in range(n)]

    for i in range(n-1,-1,-1):
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1
    
    return B

N = int(input())
A = list(map(int,input().split()))
ans = countingSort(A)
print(' '.join(map(str,ans)))

