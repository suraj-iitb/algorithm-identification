def bubbleSort(A,N):
    flag = True
    count = 0
    while flag:
        flag = False
        for j in reversed(range(1,n)):
            if A[j] < A[j-1]:
                v = A[j]
                A[j] = A[j-1]
                A[j-1] = v
                count += 1 
                flag = True
    print(" ".join(map(str,A)))
    print(count)

n = int(input())
numlist = [int(x) for x in input().split()]

bubbleSort(numlist,n)
