n = int(input())
def CountingSort(A, B, k):
    C = [0] * (k + 1)
    for j in range(n):
        C[A[j]] += 1
    C[0] -= 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in A[::-1]:
        B[C[j]] = j
        C[j] -= 1
A = list(map(int, input().split()))
B = [0] * n
CountingSort(A, B, max(A))
print(" ".join(map(str,B)))

