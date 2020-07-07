n = int(input())
A = list(map(int,input().split()))
cnt = 0
flag = True
while flag:
    flag = False
    for i in range(n-1,0,-1):
        if A[i] < A[i-1]:
            A[i],A[i-1] = A[i-1],A[i]
            cnt += 1
            flag = True
print(" ".join(map(str,A)))
print(cnt)
