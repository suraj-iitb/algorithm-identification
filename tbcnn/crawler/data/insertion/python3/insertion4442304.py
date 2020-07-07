def insertionSort(A, N):
    for i in range(N):
        v = A[i]
        j = i -1
        while j >= 0 and A[j] > v:
             A[j+1] = A[j]
             j -= 1
        A[j+1] = v
        b = 0
        for i in A:
            b +=1
            if b == N:
                print(i, end ="")
            else:
                print(i, end =" ")
        print()
n = int(input())
a = [int(i) for i in input().split()]
insertionSort(a,n)
