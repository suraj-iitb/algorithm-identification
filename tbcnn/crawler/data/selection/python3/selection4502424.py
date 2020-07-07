n = int(input())
R = [int(x) for x in input().split()]#リスト内包表記
def selected_sort(a,n):
    count=0
    judge=False
    for i in range(0,n-1):#一個前までやれば全てソートが完了する
        minj=i#未ソート部の先頭をminとみなす
        for j in range(i,n):
            if a[j]<a[minj]:#
                minj=j#最小インデックスの更新
                judge=True#インデックスが更新されたかどうかの判定
        a[i],a[minj]=a[minj],a[i]#最小値と未ソートの先頭をswap
        if judge:
            count+=1
        judge=False
    print(*a)
    print(count)
        

selected_sort(R,n)
