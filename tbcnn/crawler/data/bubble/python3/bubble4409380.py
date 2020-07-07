N = int(input())
A = list(map(int,input().split()))

change = 0
for i in range(N):
    for j in range(N-i-1):
        if A[j] > A[j+1]:
            A[j],A[j+1] = A[j+1],A[j]
            change += 1
print(" ".join(map(str,A)))
print(change)
