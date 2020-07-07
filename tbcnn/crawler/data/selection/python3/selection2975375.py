n = int(input())
nlist = list(map(int, input().split()))
def SelectionSort(A, n):
    count = 0
    for i in range(n):
        mini = i
        a = A[i]
        for j in range(i, n):
            if(A[j] < A[mini]):
                mini = j
        if(mini != i):
            A[i] = A[mini]
            A[mini] = a
            count += 1
            
    for i in range(n):
        if(i == n-1):
            print('{}'.format(A[i]), end = '')
        else:
            print('{}'.format(A[i]), end = ' ')
    print()
    print(count)
SelectionSort(nlist, n)
