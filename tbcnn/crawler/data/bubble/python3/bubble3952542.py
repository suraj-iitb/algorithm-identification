# 諸々の入力
N=int(input())
A=list(map(int,input().split()))

flag=1 # flagはbool型みたいなもの
count=0 # 反転数

# バブルソート
while flag==1:
    flag=0
    for j in range(N-1,0,-1):
        if A[j-1]>A[j]:
            A[j-1],A[j]=A[j],A[j-1]
            flag=1
            count+=1

# 答えと反転数の出力
ans=list(map(str,A))
print(' '.join(ans))
print(count)

