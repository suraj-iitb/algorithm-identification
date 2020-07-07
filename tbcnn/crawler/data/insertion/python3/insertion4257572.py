N = int(input())
A = list(map(int, input().split()))
for i in range(N):
    key = A[i]
    j = i - 1
    while A[j] > key and j >=0:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    print(*A)
