def countingSort(A, B, k):
    C = [0]*k

    for i in range(len(A)):
        C[A[i]] = C[A[i]] + 1
        #print(C)

    for i in range(1, k):
        C[i] = C[i] + C[i-1]
        #print(C)
    
    for j in range(len(A)):
        B[C[A[len(A)-1-j]]-1] = A[len(A)-1-j]
        C[A[len(A)-1-j]] = C[A[len(A)-1-j]] - 1
        #print(C)

    return " ".join(map(str, B))

n = int(input())
X = [0]*n
Y = list(map(int, input().split()))

print(countingSort(Y, X, max(Y)+1))
