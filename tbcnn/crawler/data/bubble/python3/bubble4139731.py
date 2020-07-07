def BubbleSort(A, N):
    j = 0
    flag = 1
    k = 0
    while flag:

        flag = 0
        
        for i in range(N-1, 0, -1):
            
            if A[i] < A[i-1]:

                A[i-1], A[i] = A[i], A[i-1]
        
                # a = A[i-1]
        
                # A[i-1] = A[i]
        
                # A[i] = a
        
                flag = 1
        
                j += 1
        # k += 1
    
    print(' '.join([str(x) for x in A]))
    print(j)

N = int(input())
A = [int(x) for x in input().split()]

BubbleSort(A, N)

                
        

