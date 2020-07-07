N = int(input())
A = list(map(int,input().split()))

flg = True
cnt = 0
i = 0
while flg:
    flg = False
    #末尾(N-1)から先頭(i)に向けてソートする
    for j in range(N-1,i,-1):
        if A[j] < A[j-1]:
            A[j],A[j-1] = A[j-1],A[j]
            cnt += 1
            flg = True
    #一番小さい数字が確定するごとにiをカウントアップ
    i += 1
print(*A)
print(cnt)

