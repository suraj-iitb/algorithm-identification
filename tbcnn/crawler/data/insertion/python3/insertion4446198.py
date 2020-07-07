from sys import stdin

N = int(stdin.readline())
A = list(map(int, stdin.readline().split()))

print(*A)
for i in range(1,N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print(*A)
