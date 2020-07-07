N = int(input())
num_list = [int(item) for item in input().split()]

def countingSort(A, k):
    B = [0 for _ in range(N+1)]
    C = [0 for _ in range(k+1)]

    for j in range(N):
        C[A[j]] += 1
    
    for i in range(1, k+1):
        C[i] = C[i] + C[i - 1]

    for j in reversed(range(N)):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1
    return B[1:]


print(*countingSort(num_list, max(num_list)))
