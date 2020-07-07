N = int(input())
A = list(map(int, input().split()))

#%%
def insertionSort(A, N):
    for i in range(1, N):
        v = A[i]    # これからソートしたい1つの数字（i番目）
        j = i - 1   # ソート済み(i-1番目まで)のインデックス
        print(' '.join(map(str, A)))

        # j以下のものを順番に右にずらしていきながら、挿入する値のインデックスを決める
        while j >= 0 and A[j] > v:
            A[j+1] = A[j] # 値を上書きしていく（右にずらしていく処理）
            j -= 1  # jがi-1を始点として、先頭に向かって減少する
        A[j+1] = v # いい感じのところで[..., 3, 3, ...]みたいになるので、左側を上書きする
    
    return A

a = insertionSort(A[:], N)
print(' '.join(map(str, a)))
