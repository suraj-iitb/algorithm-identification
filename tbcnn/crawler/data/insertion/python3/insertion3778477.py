n = int(input())

A = [int(s) for s in input().split()]
print(*A)

for i in range(1, n):
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key:
        j -= 1
    A.insert(j+1, key)
    del A[i+1]

    print(*A)
