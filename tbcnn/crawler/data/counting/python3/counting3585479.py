n = int(input())
A = [int(i) for i in input().split()]

def countingSort(A, k):
    B = [0 for i in range(len(A))]
    C = [0 for i in range(k+1)]
    for a in A:
        C[a] += 1
    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
    for a in reversed(A):
        B[C[a]-1] = a
        C[a] -= 1
    return B

print(*countingSort(A, 10000))

