def selectionSort(A,N):
    cnt = 0
    for i in range(N-1):
        minj = i
        flag = 0
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
                flag = 1
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
        if flag: cnt+=1

    print(*A)
    print(cnt)

n = int(input())
ls = list(map(int,input().split()))
selectionSort(ls,n)        

