n = int(input())
A = [int(x) for x in input().split()]

flag = 1
i = 0
cnt = 0
while flag==1:
    flag = 0
    for j in range(i+1,n)[::-1]:
        #print(j)
        if A[j-1]>A[j]:
            A[j-1],A[j] = A[j],A[j-1]
            flag = 1
            cnt += 1
    i += 1
print(*A)
print(cnt)

