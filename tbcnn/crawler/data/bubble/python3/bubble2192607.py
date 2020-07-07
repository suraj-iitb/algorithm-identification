N = int(input())

A = [int(n) for n in input().split()]

flag = 1
num_c  = 0
while(flag):
    flag = 0
    for j in range(1, N):
        if A[j] < A[j-1]:
            v = A[j]
            A[j] = A[j-1]
            A[j-1] = v
            num_c += 1
            flag = 1

print((" ").join((str(a) for a in A)))
print(num_c)
