def selectionSort(A,N):
    count=0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        A[i],A[minj] = A[minj],A[i]
        if i != minj:
            count +=1
    return A,count

N = int(input())
A = list(map(int,input().split()))
A,count = selectionSort(A,N)
print(" ".join(map(str,A)))
print("%d"%(count))

