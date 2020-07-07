n = int(input())
nums = list(map(int, input().split()))

def insertion_sort(lis, num):
    print(' '.join(map(str, lis)))
    for i in range(1, num):
        v = lis[i]
        j = i - 1  # j は iの前の数
        while j >= 0 and lis[j] > v:  # jが0以上で配列のj番目の要素が現在の要素より大きい場合
            lis[j + 1] = lis[j]  # 配列j+1番目の要素に配列j番目の要素を格納
            # print(' '.join(lis))
            j -= 1  # jを-1
            lis[j + 1] = v  # 配列j+1番目の要素にvを格納
        print(' '.join(map(str, lis)))
    return lis

insertion_sort(nums, n)

