def SelectionSort(A, N):

    changenum = 0

    for i in range(0, N):
        minj = i

        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
                
        if minj != i:
            changenum += 1
            A[minj], A[i] = A[i], A[minj]
        
    
    print(' '.join([str(x) for x in A]))
    print(changenum)

N = int(input())
A = [int(x) for x in input().split()]

SelectionSort(A, N)
