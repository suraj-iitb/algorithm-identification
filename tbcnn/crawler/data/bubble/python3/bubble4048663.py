N = int(input())
A = list(map(int,input().split()))
flag = True
count = 0
while flag:
    flag = False
    for i in reversed(range(1,N)):
        if A[i] < A[i-1]:
            A[i-1],A[i] = A[i],A[i-1]
            flag = True
            count += 1
print(*A)
print(count)
