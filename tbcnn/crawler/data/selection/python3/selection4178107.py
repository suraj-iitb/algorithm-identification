def SelectionSort(A, N):
    count = 0
    for i in range(N):
        flag = 0
        minj = i
        j = i - 1
        for j in range(i,N):
            if A[j] < A[minj]:
                flag = 1
                minj = j
            
        if flag == 1:
            a = A[minj]
            A[minj] = A[i]
            A[i] = a
            count += 1
 
    return(A, count)

N = int(input())
A = list(map(int,input().split()))

A, count = SelectionSort(A,N)
print(' '.join(map(str, A)))
print(count)
