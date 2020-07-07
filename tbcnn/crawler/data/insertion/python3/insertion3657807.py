def insertion_sort(A, n):
    for i in range(n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1], A[j] = A[j], A[j+1]
            j-=1
        A[j+1] = v
        print(*A)
    
n = int(input())
A = list(map(int, input().split()))
insertion_sort(A, n)
