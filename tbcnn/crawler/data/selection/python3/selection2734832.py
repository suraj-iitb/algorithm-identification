def selectionSort(A, N):
    swapnum= 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i!=minj:
            temp = A[i]
            A[i] = A[minj]
            A[minj] = temp
            swapnum += 1
    return swapnum
def showlist(A):
    for i in range(len(A)):
        if i==len(A)-1:
            print(A[i])
        else:
            print(A[i], end=' ')
N = eval(input())
A = list(map(int, input().split()))
swapnum = selectionSort(A, N)
showlist(A)
print(swapnum)
