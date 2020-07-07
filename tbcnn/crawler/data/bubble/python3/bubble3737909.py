def bubblesort(A, n):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(1,n):
            if A[n-i] < A[n-i-1]:
                A[n-i], A[n-i-1] = A[n-i-1], A[n-i]
                count = count + 1
                flag = 1
        
    A_str = [str(a) for a in A]
    A_str = " ".join(A_str)
    print(A_str)
    print(count)

n = int(input())
A = list(map(int, input().split()))
bubblesort(A, n)
