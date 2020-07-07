
def countingSort(A, B, k):
    C = [0 for _ in range(k+1)]
    for i in range(n):
        C[A[i]] += 1
    for i in range(1, k):
        if i > 0:
            C[i] += C[i-1]
    for i in reversed(range(n)):
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1

n = int(input())
A = list(map(int, input().split(" ")))
B = [0 for _ in range(n)]
countingSort(A, B, 10000)
print(*B)
