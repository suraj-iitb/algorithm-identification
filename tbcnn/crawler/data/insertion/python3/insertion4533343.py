def insertion_sort(A,N):
    sorted_A = A.copy()
    print(*sorted_A)
    for i in range(1,N):
        v = sorted_A[i]
        j = i-1
        while (j>=0)&(sorted_A[j]>v):
            sorted_A[j+1] = sorted_A[j]
            j -= 1
        sorted_A[j+1] = v
        print(*sorted_A)
        

N = int(input())
A = list(map(int, input().split()))

insertion_sort(A,N)
