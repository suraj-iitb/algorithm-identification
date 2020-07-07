import math
import sys

# 比較回数をここに記録
# 理論上 n * lg n を越えることはない。
_exchange = 0

def merge_sort(A, left, right):
    """数列 A を in place に昇順にソートする。

    left は A の先頭のインデックス、right は末尾のインデックスのひとつ後ろ。
    """
    if left + 1 < right:
        mid = (left  + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

def merge(A, left, mid, right):
    """ソート済みの部分列をマージする。

    数列 A の left から mid - 1 の要素、mid から right - 1 までの
    ２つの部分列はソート済みである。これをマージして、left から right - 1 まで
    ソートする。
    """
    first = A[left:mid]
    first.append(math.inf)  # 番兵
    second = A[mid:right]
    second.append(math.inf) # 番兵

    global _exchange
    i = j = 0
    for k in range(left, right):
        _exchange += 1
        if first[i] <= second[j]:
            A[k] = first[i]
            i += 1
        else:
            A[k] = second[j]
            j += 1


if __name__ == '__main__':
    n = int(input())
    A = list(map(int, sys.stdin.readline().split()))

    merge_sort(A, 0, n)
    print(*A)
    print(_exchange)

