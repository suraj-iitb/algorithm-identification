# ALDS1_6_A Counting Sort
import sys
def counting_sort(A, B):
    k = max(A) + 1
    C = [0] * k  # k = max(A)

    for i in range(len(A)):
        C[A[i]] += 1

    for j in range(1, k):
        C[j] = C[j - 1] + C[j]

    for i in range(len(A) - 1, -1, -1):
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1


n = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))
B = [0] * n

counting_sort(A, B)
print(' '.join(map(str, B)))
