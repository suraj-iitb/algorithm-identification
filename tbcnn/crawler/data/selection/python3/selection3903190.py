def selectionSort(A,N):
    cnt=0
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[minj]>A[j]:
                minj=j
        if A[i]!=A[minj]:
            A[i],A[minj]=A[minj],A[i]
            cnt+=1
    return A,cnt

N = int(input())
A = list(map(int,input().split()))
A,cnt = selectionSort(A,N)
print(*A)
print(cnt)
