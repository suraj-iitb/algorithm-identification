#初期定義
global result
global s_list
result = 0

#アルゴリズム：ソート
def merge(left, mid, right):
    global result
    
    n1 = mid - left
    n2 = right - mid
    inf = 10**9
    L_list = s_list[left: mid] + [inf]
    R_list = s_list[mid: right] + [inf]

    i = 0
    j = 0
    for k in range(left, right):
        result += 1
        if L_list[i] <= R_list[j]:
            s_list[k] = L_list[i]
            i += 1
        else:
            s_list[k] = R_list[j]
            j += 1

#アルゴリズム：マージソート
def mergeSort(left, right):
    if (left + 1) < right:
        mid = (left + right) // 2
        mergeSort(left, mid)
        mergeSort(mid, right)
        merge(left, mid, right)

#初期値
n = int(input())
s_list = list(map(int, input().split()))

#処理の実行
mergeSort(0, n)

#結果の表示
print(" ".join(map(str, s_list)))
print(result)
