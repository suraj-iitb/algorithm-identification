N = int(input())
A = list(map(int,input().split()))

cnt = 0
flag = 1
while flag == 1:
    flag = 0
    for j in range(N-1,0,-1):
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            flag = 1
            cnt += 1
print(" ".join([str(s) for s in A]))
print(cnt)
        

