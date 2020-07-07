def insertionSort(A, N):
    for i in range(1, N):
        print(" ".join([str(a) for a in A]))
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
    print(" ".join([str(a) for a in A]))    
    

N = int(input().rstrip())
A = [int(a) for a in input().rstrip().split(" ")]
insertionSort(A, N)
