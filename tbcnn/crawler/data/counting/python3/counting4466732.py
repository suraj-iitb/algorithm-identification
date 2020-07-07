def counting_sort(A, B, k):
    n = len(A)
    C = [0] * (k + 1)

    for i in range(n):
        C[A[i]] += 1

    for i in range(k):
        C[i + 1] += C[i]
    
    for i in range(n-1, -1, -1):
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1

n = int(input())
A = list(map(int, input().split()))

B = [0] * n

counting_sort(A, B, 10000)
print(" ".join(map(str, B)))
