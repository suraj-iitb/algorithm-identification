def selectionSort():
    N = int(input())
    A = list(map(int, input().split()))
    C = 0
    
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        
        A[i], A[minj] = A[minj], A[i]
        if not(minj == i):
            C += 1
    
    print(*A)
    print(C)
    
selectionSort()
