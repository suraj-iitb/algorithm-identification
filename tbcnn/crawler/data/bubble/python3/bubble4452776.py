n = int(input())
As = input().split()
A = [int(i) for i in As]
f = True
c = 0

while f:
    f = False
    for i in range(n-1):
        if A[i+1] < A[i]:
            w = A[i+1]
            A[i+1] = A[i]
            A[i] = w
            c += 1
            f = True

for i in range(n-1):
    print("{} ".format(A[i]), end="")
print(A[n-1])
print(c)

