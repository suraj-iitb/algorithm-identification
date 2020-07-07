def bubbleSort(A,N):
    global cnt
    flag=1
    while flag:
        flag=0
        for j in range(N-1,0,-1):
            if A[j]<A[j-1]:
                A[j],A[j-1]=A[j-1],A[j]
                flag=1
                cnt+=1
N = int(input())
A = list(map(int,input().split()))
cnt = 0
bubbleSort(A,N)
print(*A)
print(cnt)
