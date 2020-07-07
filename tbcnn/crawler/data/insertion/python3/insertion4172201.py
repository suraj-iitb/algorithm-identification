N = int(input())
A = list(map(int,input().split()))
i = 0
k = 0

for i in range(len(A)):
    v = A[i]
    j = i-1
    while j>=0 and A[j]>v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print(*A)

