def insertionSort(A, N):
    print(' '.join(map(str, A)))
    for i in range(1, N):
        value = A[i]
        j = i - 1
        while j >= 0 and A[j] > value:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = value
        print(' '.join(map(str, A)))


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    insertionSort(A, N)
