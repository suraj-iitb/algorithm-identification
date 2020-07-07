"""
# 標準入力取得
## 文字列
 = sys.stdin.readline().rstrip()
 = list(sys.stdin.readline().rstrip())

## 数値
 = int(sys.stdin.readline())
 = map(int, sys.stdin.readline().split())
 = list(map(int, sys.stdin.readline().split()))
 = [list(map(int,list(sys.stdin.readline().split()))) for i in range(h)]  # 二次元配列入力　二次元マップみたいな入力のとき

# 0埋め, 小数点出力桁指定時のときの出力
a = 100
b = 0.987654321
print("{0:06d}-{1:6f}".format(a,b))
000100-0.987654

# 文字列をリストに格納
char_list = list("abcd") # ["a","b","c","d"]
"""

import math
import sys
import itertools
import queue
from fractions import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

mod = 1000000007

if __name__ == "__main__":
    n= int(sys.stdin.readline())
    l= list(map(int, sys.stdin.readline().split()))
    c=0
    for i in range(n):
        minj=i
        for j in range(i,n):
            if l[j] < l[minj]:
                minj=j
        if i!=minj:
            c+=1
            temp=l[minj]
            l[minj]=l[i]
            l[i]=temp
    print(*l)
    print(c)

