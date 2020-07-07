N = int(input())
A = list(map(int, input().split()))

def SelectionSort(A):
    count = 0
    for i in range(N):
        min = i
        for j in range(i, N):
            if A[j] < A[min]:
                min = j
        if A[i] > A[min]:
            A[i], A[min] = A[min], A[i]
            count += 1
    print(' '.join(map(str, A)))
    print(count)

SelectionSort(A)
