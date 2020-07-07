N = int(input())
As = list(map(int, input().split()))
print(" ".join([str(a) for a in As]))

for i in range(1,N):
    tmp = As[i]
    j = i - 1
    # 上にさかのぼりながら挿入できるところを探す
    # さかのぼりきる & 今より大きいところが見つかる
    while j >= 0 and As[j] > tmp:
        As[j+1] = As[j]
        j -= 1 
    As[j+1] = tmp
    print(" ".join([str(a) for a in As]))

