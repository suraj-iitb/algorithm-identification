def insertionSort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print (' '.join([str(x) for x in A]))

if __name__ == '__main__':
    length = int(input())
    hoge = [int(x) for x in input().split()]
    print (' '.join([str(x) for x in hoge]))
    insertionSort(hoge, length)
