# https: // onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A
# 要素のmaxであるkさえわかっていればO(n+k)でソートできる高速なソート。天才かと思った。
# ソートしたい配列の数字をidxに対応させて、count 配列を作成. count配列を累積和。それがidxに対応しているというびっくり方法。
# ! 0 based-indexにするために、本とは違う実装


n = int(input())
A = list(map(int, input().split()))
A.sort()

print(*A)

