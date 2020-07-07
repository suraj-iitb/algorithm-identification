def CountingSort(A, k):
    C = [0] * k
    B = C[:]
    for a in A:
        C[a] += 1
    for i in range(1, len(C)):
        C[i] += C[i - 1]
    for i in range(len(A) - 1, -1, -1):
        B[C[A[i]]] = A[i]
        C[A[i]] -= 1
    return B



if __name__ == '__main__':
    N = int(input())
    A = [int(i) for i in input().strip().split()]
    sorted_A = CountingSort(A, int(3E6))
    print(' '.join([str(a) for a in sorted_A[1:len(A) + 1]]))
