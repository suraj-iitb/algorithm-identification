def insertionSort(A, N): # N個の要素を含む0-オリジンの配列A
    for i in range(1, N):
        print(' '.join([str(p) for p in A]))
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j-=1
        A[j+1] = v
    print(' '.join([str(p) for p in A]))
        
n = int(input())
a_list = [int(i) for i in input().split()]
insertionSort(a_list, n)
