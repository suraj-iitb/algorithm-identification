def insertionSort(A, N):
    print(' '.join([str(i) for i in A]))
    for i in range(1, N):
        # print(' '.join([str(i) for i in A]))
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        print(' '.join([str(i) for i in A]))
        

if __name__ == "__main__":
    N = int(input())
    A = [int(i) for i in input().strip().split()]
    insertionSort(A, N)
