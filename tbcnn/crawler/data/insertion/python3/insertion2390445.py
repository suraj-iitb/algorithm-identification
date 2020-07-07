def insertionSort(A, N):
    for i in range(1, N):
        print (*A)
        v = A[i]
        j = i - 1
        while j>= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
    return A


if __name__ == "__main__":
    N = int(input())
    A = [int(i) for i in input().split()]

    print (*insertionSort(A, N))
