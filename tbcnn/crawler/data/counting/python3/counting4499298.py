n = int(input())
A = [int(i) for i in input().split()]

def countingSort(A, k):
    B = [0] * len(A)
    C = [0]*(k+1)
    
    for j in range(len(A)):
        C[A[j]] += 1
    for i in range(1, k+1):
        C[i] += C[i-1]
    
    for j in range(len(A)-1, -1, -1):
#         print(B, A[j], C[A[j]])
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
    return B

A = countingSort(A, max(A))
print(" ".join([str(s) for s in A]))
