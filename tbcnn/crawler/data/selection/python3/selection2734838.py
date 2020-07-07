def selectionSort(A,N):
  
    count = 0
    for i in range(N):
        
        minj = i
        
        for j in range(i,N,1):
           
            if A[j] < A[minj]:
                minj = j
                
        
        if minj != i:
            count = count + 1
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
    print(' '.join(map(str,A)))
    print(count)
    
N = int(input())
A = input()
A = list(map(int,A.split()))   
selectionSort(A,N)
