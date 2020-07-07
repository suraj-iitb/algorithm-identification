N = int(input())
A = [int(x) for x in input().split()]
cnt = 0

for i in range(N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            # ????°???????index?????´??°
            minj = j

    if A[minj] != A[i]:
        cnt += 1
    # i???????????¨???
    buf = A[minj]
    A[minj] = A[i]
    A[i] = buf


print(' '.join(str(x) for x in A))
print(cnt)
