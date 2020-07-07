n = int(input())
A = list(map(int, input().split()))
count = 0

for i in range(n):
    j = i
    while(j>=1):
        if A[j] < A[j-1]:
            v = A[j-1]
            A[j-1] = A[j]
            A[j] = v
            count += 1
        j -= 1

print(" ".join(map(str, A)))
print(str(count))
