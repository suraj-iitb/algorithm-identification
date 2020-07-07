
# バブルソート
n = int(input())
A = list(map(int, input().split()))

#%%
def bubbleSort(A, N):
    flag = True
    i = 0 # 未ソートのindex
    cnt = 0
    while flag:
        flag = False
        for j in range(N-1, i, -1): # 逆順に交換していく
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j] # 大小関係が間違ってたら交換する
                cnt += 1
                flag = True
        i += 1
    return A, cnt

ans, c = bubbleSort(A[:], n)
print(' '.join(map(str, ans)))
print(c)
