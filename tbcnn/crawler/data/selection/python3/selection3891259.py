N = int(input())
A = [int(x) for x in input().split()]

def selectionSort(A, N):
    count = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if not minj == i: count += 1
        A[i],  A[minj] = A[minj], A[i]
        
    return count

count = selectionSort(A, N)        
print(' '.join(map(str,A)))
print("%d"%(count))
