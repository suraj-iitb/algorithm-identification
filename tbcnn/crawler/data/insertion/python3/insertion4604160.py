def InsertionSort(A, N=1):
    N = min(N, len(A))
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
    return A


N = int(input())
a = list(map(int, input().split()))

for i in range(len(a)):
    print(' '.join(map(str, InsertionSort(a, i+1))))
