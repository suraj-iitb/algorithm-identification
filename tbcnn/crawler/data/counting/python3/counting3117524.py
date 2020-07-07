def counting_sort(A, n, k):
    C = [0] * (k + 1)
    B = [0] * n
    for ai in A:
        C[ai] += 1
    # C[i]にi以下の出現数を記録する
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for ai in reversed(A):
        B[C[ai] - 1] = ai
        C[ai] -= 1
    return B
n = int(input())
k = 10000
print(*counting_sort(list(map(int, input().split())), n, k))
