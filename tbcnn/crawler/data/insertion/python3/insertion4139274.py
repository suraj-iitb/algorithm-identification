
def InsertionSort(A):
    i = 0
    j = 0
    print(' '.join([str(x) for x in A]))
    for i in range(1, N):
        movenum = A[i]
        j = i - 1
        while j >= 0 and movenum < A[j] : 
            
            A[j+1] = A[j]
        
            j -= 1

        A[j + 1] = movenum
        print(' '.join([str(x) for x in A]))

    
        
N = int(input())
A = [int(x) for x in input().split()]
InsertionSort(A)

