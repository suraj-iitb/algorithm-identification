N = int(input())
A = list(map(int,input().split()))

flag = True
count = 0

while flag:
    flag = False
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            count += 1
            flag = True

print(*A)
print(count)

