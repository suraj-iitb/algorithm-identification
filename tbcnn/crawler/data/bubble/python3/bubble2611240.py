def bubbleSort(A,N):
    flag = 1
    i = 0
    count = 0
    while flag:
        flag = 0
        for j in range(N-1,i,-1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                count += 1
        i += 1
    return A,count


N = int(input())
A = list(map(int,input().split(' ')))

A,count = bubbleSort(A,N)

for i in range(len(A)):  # output
    if i == len(A) - 1:
        print(A[i])
    else:
        print(A[i], end=' ')

print(count)
