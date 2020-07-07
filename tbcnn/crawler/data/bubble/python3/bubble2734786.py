def bubbleSort(A, N):
    flag = 1
    i = 0
    swapnum = 0
    while flag:
        flag = 0
        for j in range(N-1, i, -1):
            if A[j] < A[j-1]:
                temp = A[j-1]
                A[j-1] = A[j]
                A[j] = temp
                swapnum += 1
                flag = 1
        i = i + 1
    return swapnum
def showlist(A):
    for i in range(len(A)):
        if i==len(A)-1:
            print(A[i])
        else:
            print(A[i], end=' ')
N = eval(input())
A = list(map(int, input().split()))
swapnum = bubbleSort(A, N)
showlist(A)
print(swapnum)
