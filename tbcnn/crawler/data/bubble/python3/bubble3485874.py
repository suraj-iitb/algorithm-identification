n = int(input())
A = list(map(int, input().split()))
flag = True
count = 0

while flag:
    flag = False
    for i in range(n-1):
        if A[i] > A[i+1]:
            v = A[i]
            A[i] = A[i+1]
            A[i+1] = v
            flag = True
            count += 1
print(" ".join(map(str, A)))
print(count)
