n = int(input())
A = list(map(int,input().split()))
count = 0

flag = 1
while flag == 1:
    flag = 0
    for i in range(n-1,0,-1):
        if A[i] < A[i-1]:
            v = A[i]
            A[i] = A[i-1]
            A[i-1] = v
            count += 1
            flag = 1
    

print(' '.join(map(str,A)))
print(count)
