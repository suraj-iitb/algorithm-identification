n = int(input())
A = [int(x) for x in input().split()]

for i in range(1, n + 1):
    print(*A)
    if i >= n: break

    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = key

