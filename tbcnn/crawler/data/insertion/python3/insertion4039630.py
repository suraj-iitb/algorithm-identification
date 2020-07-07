def InsertionSort(A,N):
    for i in range(1,N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = v
        for j in range(0,N-1):
            print("{0} ".format(A[j]),end = '')
        print(A[N-1])


N = int(input())
A = list(map(int,input().split()))

for i in range(0,N-1):
    print("{0} ".format(A[i]),end = '')
print(A[N-1])

InsertionSort(A,N)

