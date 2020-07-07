n = int(input())
A = list(map(int,input().split()))
f = 1 
c = 0

while f == 1:
    f = 0
    for j in range(n-1,0,-1):
        if A[j] < A[j-1]:
            inc = A[j]
            A[j] = A[j-1] 
            A[j-1] = inc
            f = 1
            c += 1
print(" ".join(map(str,A)))
print(c)
