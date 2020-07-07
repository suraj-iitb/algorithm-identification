def printer(A):
    ret = str(A[0])
    for i in range(1, len(A)):
        ret += " " + str(A[i])
    print(ret)
    return True


n = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(n):
    minj = i
    for j in range(i, n):
        if A[minj] > A[j]:
            minj = j
    if i != minj:
        ans += 1
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
printer(A)
print(ans)
