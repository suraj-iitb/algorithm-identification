def counting_sort(A, B, n, k):
    C = [0] * (k+1)
    for ai in A:
        C[ai] += 1
    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
    for j in range(n)[::-1]:
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
    return B
n = int(input())
A = list(map(int, input().split(' ')))
k = max(A)
B = [0] * n
sorted_A = counting_sort(A, B, n, k)
print(" ".join(map(str, sorted_A)))
