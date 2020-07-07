n = int(input())
A = list(map(int,input().split()))

for i in range(n):
    v = A[i]
    j = i-1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j = j-1
        A[j+1] = v
    for k in range(n-1):
        print(str(A[k]) + " ", end = "")
    print(str(A[n-1]))
