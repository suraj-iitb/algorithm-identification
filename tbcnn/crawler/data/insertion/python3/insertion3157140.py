def InsertionSort(A):
    print(' '.join(map(str, A)))
    for i in range(1,len(A)):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j-=1
            A[j+1] = key
        print(' '.join(map(str, A)))

    return A

input()
a=[i for i in map(int, input().split())]
InsertionSort(a)
