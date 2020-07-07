n = int(input())
A = [int(i) for i in input().split()]

flag = 1
count = 0
while flag:
    flag = 0
    for j in range(n-1,0,-1):
        if A[j] < A[j-1]:
            A[j],A[j-1] = A[j-1],A[j]
            flag = 1
            count += 1
print(" ".join(map(str,A)))
print(count)
