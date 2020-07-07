N = int(input())
A = [int(a) for a in input().split()]

print(*A)
for i in range(1, N):
    j = i-1
    key = A[i]
    while j >= 0 and key <= A[j]:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    print(*A)
