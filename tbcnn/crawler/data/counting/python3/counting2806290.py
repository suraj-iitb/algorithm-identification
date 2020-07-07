def countingSort(A):
    k = max(A)
    B = [0]
    B.extend(A)
    C = []
    n = len(A)
    for i in range(k + 1):
        C.append(0)

    for j in range(0, n):
        C[A[j]] += 1
    
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    
    for j in range(n - 1, -1, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1
    print(' '.join(list(map(str, B[1:]))))
    return
N = int(input())
a = list(map(int, input().split()))
countingSort(a)
