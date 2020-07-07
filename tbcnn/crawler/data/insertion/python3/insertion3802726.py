r = int(input())
A = list(map(int, input().split()))

print(" ".join(map(str, A)))

for i in range(1, r):
    j = i - 1
    v = A[i]
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j-=1
    A[j+1] = v
    print(" ".join(map(str, A)))
