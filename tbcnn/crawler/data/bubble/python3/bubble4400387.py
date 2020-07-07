N = int(input())
A = list(map(int, input().split()))
times = 0

flag = True

while flag:
    flag = False
    for i in range(N-1, 0, -1):
        if A[i] < A[i-1]:
            A[i], A[i-1] = A[i-1], A[i]
            times += 1
            flag = True

print(" ".join(map(str, A)))
print(times)
