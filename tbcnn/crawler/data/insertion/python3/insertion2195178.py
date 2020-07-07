def insertionSort(n, A):
    for i in range(n):
        t = A[i]
        j = i - 1
        while (j >= 0) and (A[j] > t):
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = t
        print(*A)
    return A


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    insertionSort(N, A)
