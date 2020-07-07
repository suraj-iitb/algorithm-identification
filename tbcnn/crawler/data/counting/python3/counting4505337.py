n = int(input())
A = list(map(int, input().split()))
c = [0] * 10001
output = [0] * n

for num in A:
    c[num] += 1

for i in range(0, max(A)):
    c[i + 1] += c[i]

for j in range(-1, -n-1, -1):
    output[c[A[j]] - 1] = A[j]
    c[A[j]] -= 1

print(*output)

