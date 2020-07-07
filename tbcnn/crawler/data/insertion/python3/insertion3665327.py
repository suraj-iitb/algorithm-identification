N = int(input())
a = list(map(int, input().split()))
print(" ".join(list(map(str, a))))

#「整列していない部分」から、順番に1つずつ取り出していく
for i in range(1,len(a)):
    
    #「挿入する値」を、変数に取り出す
    tmp=a[i]
    
    #挿入する位置の変数を用意する
    ins=0
    
    #「整列済みの部分」のどこに挿入すればいいのかを、後ろから前に向かって順番に見ていく
    for j in range(i-1,-1,-1):
        
        #もし「挿入する値」が小さければ
        if tmp < a[j]:
            
            #そこに挿入できるように、調べた値を１つ後ろへずらす
            a[j+1]=a[j]
        else :
            
            #もし「挿入する値」が小さくなければ、そこでずらす処理を止める
            ins=j+1
            break
    
    #ずらす処理が終わった位置に「挿入する値」を入れる    
    a[ins]=tmp
    
    #ソート後の配列を表示する
    print(" ".join(list(map(str, a))))


