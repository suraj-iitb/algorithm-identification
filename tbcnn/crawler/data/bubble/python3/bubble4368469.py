def BubbleSort(A,N):
    count = 0
    flag = 1
    while flag == 1:
        flag = 0
        for j in range(n-1,0,-1):
            if A[j] < A[j-1]:
                key = A[j]
                A[j] = A[j-1]
                A[j-1] = key
                count += 1
                flag = 1
    L=[str(ai) for ai in A]
    L=" ".join(L)
    print(L)
    return count
    
n = int(input())
a = list(map(int,input().split()))
count = BubbleSort(a,n)
print(count)
