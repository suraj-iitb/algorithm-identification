def counting_sort(A, k):
    B = [0 for _ in range(len(A))]
    C = [0 for _ in range(k)]
    for i in range(len(A)):
        C[A[i]] += 1

    for i in range(1, k):
        C[i] = C[i] + C[i-1]

    for i in range(len(A)-1, -1, -1):
        B[C[A[i]]-1] = A[i]
        C[A[i]] = C[A[i]] - 1
    
    return B
    
n = int(input())
A = list(map(int, input().split()))
k = max(A) + 1
B = counting_sort(A, k)
print(*B)
