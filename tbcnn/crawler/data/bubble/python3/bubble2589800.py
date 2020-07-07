def bubbleSort(A,N,cnt=0):
    flag = 1
    while flag:
        flag = 0
        for i in range(N-1,0,-1):
            if A[i-1] > A[i]:
                A[i-1] , A[i] = A[i] , A[i-1]
                cnt += 1
                flag = 1
    return A , cnt

N = int(input())
A = list(map(int,input().split()))
X , cnt = bubbleSort(A,N)
print(*X)
print(cnt)
