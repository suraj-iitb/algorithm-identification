import sys

def CountingSort(A, B, k):
    C = [0] * (k+1)

    #   C[i] に i の出現数を記録する
    for j in A:
        C[j]+=1

    # C[i] に i 以下の数の出現数を記録する
    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]
    for j in range(n-1, -1, -1): # n downto 1
        B[C[A[j]]-1] = A[j]
        C[A[j]]-=1

    return B


n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = [0] * n

CountingSort(a, b, max(a))
print(' '.join(map(str, b)))
