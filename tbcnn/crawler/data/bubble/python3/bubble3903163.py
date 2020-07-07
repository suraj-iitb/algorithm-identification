def bubbleSort(A,N):
    flag=1
    cnt=0
    while flag:
        flag=0
        for i in range(N-1,0,-1):
            if A[i]<A[i-1]:
                A[i],A[i-1]=A[i-1],A[i]
                flag=1
                cnt+=1
    return A,cnt

N = int(input())
A = list(map(int,input().split()))
A,cnt = bubbleSort(A,N)
print(*A)
print(cnt)
