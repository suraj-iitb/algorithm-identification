def bubbleSort(A,N):
    flag = 1
    cnt = 0
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                cnt +=1
    print(*A)
    print(cnt)

n = int(input())
ls = list(map(int,input().split()))

bubbleSort(ls,len(ls))

