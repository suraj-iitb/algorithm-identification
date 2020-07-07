def insertion_sort(A,n):
    for i in range(n):
        v = A[i]
        j = i-1
        while(j>=0 and A[j]>v):
            A[j+1] = A[j]
            j = j-1
        A[j+1] = v
        for i in range(n-1):
            print(A[i],"",end="")
        print(A[n-1])

n = int(input())
A_idx = [int(i) for i in input().split()]

insertion_sort(A_idx,n)
