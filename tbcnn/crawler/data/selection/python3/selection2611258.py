def selectionSort(A,N):
    count = 0
    for i in range(0,N-1):
        minj = i
        for j in range(i+1,N):
            if A[j] < A[minj]:
                minj = j
        tmp = A[minj]
        A[minj] = A[i]
        A[i] = tmp
        if i != minj:
            count += 1

    return A,count

N = int(input())
A = list(map(int,input().split(' ')))

A,count = selectionSort(A,N)

for i in range(len(A)):  # output
    if i == len(A) - 1:
        print(A[i])
    else:
        print(A[i], end=' ')

print(count)
