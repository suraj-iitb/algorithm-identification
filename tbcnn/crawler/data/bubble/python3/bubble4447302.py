N = int(input())
A = list(map(int, input().split()))

flag = True
j = 1
cnt = 0

while flag:
    flag = False
    for i in reversed(range(j, N)):
        if A[i] < A[i-1]:
            tmp = A[i]
            A[i] = A[i-1]
            A[i-1] = tmp
            cnt += 1
            flag = True
    j += 1

result = [str(i) for i in A]
print(' '.join(result))
print(cnt)

