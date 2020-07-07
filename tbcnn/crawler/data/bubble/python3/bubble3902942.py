N = int(input())
A = list(map(int, input().split()))
cnt = 0
flag = True
while flag:
    flag = False
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            (A[j], A[j-1]) = (A[j-1], A[j])
            cnt += 1
            flag = True
print(" ".join(list(map(str, A))))
print(cnt)
