N = int(input())
A = list(map(int, input().split()))
count = 0
flag = 1
i = 0

while flag:
    flag = 0
    for j in range(N - 1, i , -1):
        if A[j - 1] > A[j]:
            v = A[j - 1]
            A[j - 1] = A[j]
            A[j] = v
            count += 1
            flag = 1
    i += 1

s = [str(a) for a in A]
s = ' '.join(s)
print(s)
print(count)

