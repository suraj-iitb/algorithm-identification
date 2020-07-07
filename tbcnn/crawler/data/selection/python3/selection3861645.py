n = int(input())
l = list(map(int,input().split()))


def selectionSort(A,n):
    count = 0
    for i in range(n):
        minj = i
        
        for j in range(i,n):
            if A[j] < A[minj]:
                minj=j
        A[i],A[minj]=A[minj],A[i]
        count = count + int( i != minj)
    return count

count=selectionSort(l,n)

print(' '.join(map(str,l)))
print(count)
