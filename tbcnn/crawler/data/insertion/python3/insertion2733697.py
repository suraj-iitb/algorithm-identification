def insertionSort(A,N):
    for i in range(N):
        v = A [i]
        j = i-1
        while j>=0 and A[j] > v:
            A[j+1] = A[j]
            j = j -1
        A[j+1] = v
        print(' '.join(map(str, A)))

N = input()
N = int(N)
A = input()
A = list(map(int, A.split()))
insertionSort(A,N)
