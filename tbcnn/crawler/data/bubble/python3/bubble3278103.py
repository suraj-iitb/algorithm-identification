n = int(input())
a = [int(i) for i in input().split()]
A=[]
for i in range(n):
    A.append(a[i])

flag = True
count = 0
while flag:
    flag = False
    for i in range(1, n):
        if A[i] < A[i-1]:
            A[i], A[i-1] = A[i-1], A[i]
            flag = True
            count += 1
print(*A)
print(count)
