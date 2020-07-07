# 入力
N=int(input())
A=list(map(int,input().split()))

count=0
# 選択ソート
for i in range(N):
    minj=i
    for j in range(i,N):
        if A[j]<A[minj]:
            minj=j
    if A[i]!=A[minj]:
        A[i],A[minj]=A[minj],A[i]
        count+=1

# 出力
B=list(map(str,A))
print(' '.join(B))
print(count)

