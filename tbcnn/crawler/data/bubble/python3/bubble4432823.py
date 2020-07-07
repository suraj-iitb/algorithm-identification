def bubbleSort(A, n):
    flag = True
    i = 0
    while flag:
        flag = False
        for j in range (1,n)[::-1]:
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                flag = True
                i += 1
    L=[str(a) for a in A]
    L=" ".join(L)
    print(L)
    print(i)



n = int(input())
A = list(map(int,input().split()))
bubbleSort(A, n)
