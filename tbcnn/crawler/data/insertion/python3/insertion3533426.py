n = int(input())
l = list(map(int, input().split()))
print(" ".join(map(str,l)))
def insertionSort(a, n):#配列aを挿入ソートで並び替える(昇順）
    for i in range(1,n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]#a[i]の位置に詰めていく処理
            j -= 1
        a[j+1] = v
        print(" ".join(map(str,a)))#１行ごとに出力
insertionSort(l,n)
