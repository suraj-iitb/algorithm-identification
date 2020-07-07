def CountingSort(A, B, k):
    C = [0] * (k + 1)
    for j in A:
        C[j] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in reversed(A):
        B[C[j]-1] = j
        C[j] -= 1


n = int(input())
A = list(map(int, input().split()))
B = [0] * n
CountingSort(A, B, max(A))
print(*B)
