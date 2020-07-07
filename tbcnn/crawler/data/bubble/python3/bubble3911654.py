N = int(input())
A = [int(n) for n in input().split()]

c = 0
flag =1
while flag:
    flag = 0
    for j in reversed(range(1,N)):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            flag = 1
            c += 1


print(" ".join([str(a) for a in A]))
print(c)
