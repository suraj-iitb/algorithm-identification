n = int(input())
nums = list(map(int,input().split()))
print(" ".join(map(str,nums)))
for i in range(1,n): #未ソートの部分列の先頭を示すループ変数
    v = nums[i] #nums[i]の値を一時的に保持しておくための変数
    j = i - 1 #ソート済み部分列からvを挿入するための位置を探すループ変数
    while j >= 0 and nums[j] > v:
        nums[j+1] = nums[j] #jにあった数をj+1(つまりi)に移す
        j -= 1 #jの位置を下げて、Falseになるまで確認する
    nums[j+1] = v
    print(" ".join(map(str,nums)))

