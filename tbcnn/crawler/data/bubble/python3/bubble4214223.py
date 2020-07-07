n = int(input())
A = [int(a) for a in input().split()]
cnt = 0
flg = True
while flg:
    flg = False
    for j in range(n-1, 0, -1):
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            cnt += 1
            flg = True
A = [str(a) for a in A]
print(" ".join(A))
print(cnt)
