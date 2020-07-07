def selectionSort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:        
            ho = A[i]
            A[i] = A[minj]
            A[minj] = ho
            count += 1
    return A, count

n = int(input())
a = [ int(i) for i in input().split()]
b , count = selectionSort(a,n)
for i in range(len(b)):
    if i == len(b)-1:
        print(b[i])
    else:
        print(b[i],end=' ')            
print(count)
