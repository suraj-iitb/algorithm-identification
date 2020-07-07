def CountingSort(A, B, k):
    C = [ 0 for i in range(k + 1)]
    
    for i in range(len(A)):
        C[A[i]] += 1

    for j in range(1, len(C)):
        C[j] = C[j] + C[j - 1]

    for j in reversed(range(len(A))):
        B[ C[ A[j] ] - 1 ] = A[j]
        C[ A[j] ] -= 1

def Main():
    n = int(input())

    A = [int(a) for a in input().split()]
    B = [0 for i in range(len(A))]
    k = max(A) + 1

    CountingSort(A, B, k)

    print(*B)

Main()
