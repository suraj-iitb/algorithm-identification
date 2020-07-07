import sys
# import bisect
# import math
# import itertools
# import numpy as np
# import collections

"""Template"""


class IP:
    """
    入力を取得するクラス
    """

    def __init__(self):
        self.input = sys.stdin.readline

    def I(self):
        """
        1文字の取得に使います
        :return: int
        """
        return int(self.input())

    def S(self):
        """
        1文字の取得(str
        :return: str
        """
        return self.input()

    def IL(self):
        """
        1行を空白で区切りリストにします(int
        :return: リスト
        """
        return list(map(int, self.input().split()))

    def SL(self):
        """
        1行の文字列を空白区切りでリストにします
        :return: リスト
        """
        return list(map(str, self.input().split()))

    def ILS(self, n):
        """
        1列丸々取得します(int
        :param n: 行数
        :return: リスト
        """
        return [int(self.input()) for _ in range(n)]

    def SLS(self, n):
        """
        1列丸々取得します（str
        :param n: 行数
        :return: リスト
        """
        return [self.input() for _ in range(n)]

    def SILS(self, n):
        """
        Some Int LineS
        横に複数、縦にも複数
        :param n: 行数
        :return: list
        """
        return [self.IL() for _ in range(n)]

    def SSLS(self, n):
        """
        Some String LineS
        :param n: 行数
        :return: list
        """
        return [self.SL() for _ in range(n)]


class Idea:
    def __init__(self):
        pass

    def HF(self, p):
        """
        Half enumeration
        半分全列挙です
        pの要素の和の組み合わせを作ります。
        ソート、重複削除行います
        :param p: list : 元となるリスト
        :return: list : 組み合わせられた和のリスト
        """
        return sorted(set(p[i] + p[j] for i in range(len(p)) for j in range(i, len(p))))

    def Bfs2(self, a):
        """
        bit_full_search2
        bit全探索の改良版
        全探索させたら2進数のリストと10進数のリストを返す
        :return: list２つ : １個目 2進数(16桁)  2個目 10進数
        """
        # 参考
        # https://blog.rossywhite.com/2018/08/06/bit-search/
        # https://atcoder.jp/contests/abc105/submissions/4088632
        value = []
        for i in range(1 << len(a)):
            output = []

            for j in range(len(a)):
                if self.bit_o(i, j):
                    """右からj+1番目のiが1かどうか判定"""
                    # output.append(a[j])
                    output.append(a[j])
            value.append([format(i, 'b').zfill(16), sum(output)])

        value.sort(key=lambda x: x[1])
        bin = [value[k][0] for k in range(len(value))]
        val = [value[k][1] for k in range(len(value))]
        return bin, val

    def S(self, s, r=0, m=-1):
        """
        ソート関係行います。色々な設定あります。
        :param s: 元となるリスト
        :param r: reversするかどうか 0=False 1=True
        :param m: （2次元配列）何番目のインデックスのソートなのか
        :return: None
        """
        r = bool(r)
        if m == -1:
            s.sort(reverse=r)
        else:
            s.sort(reverse=r, key=lambda x: x[m])

    def bit_n(self, a, b):
        """
        bit探索で使います。0以上のときにTrue出します
        自然数だからn
        :param a: int
        :param b: int
        :return: bool
        """
        return bool((a >> b & 1) > 0)

    def bit_o(self, a, b):
        """
        bit探索で使います。1のときにTrue出すよ
        oneで1
        :param a: int
        :param b: int
        :return: bool
        """
        return bool(((a >> b) & 1) == 1)

    def ceil(self, x, y):
        """
        Round up
        小数点切り上げ割り算
        :param x: int
        :param y: int
        :return: int
        """
        return -(-x // y)

    def ave(self, a):
        """
        平均を求めます
        :param a: list
        :return: int
        """
        return sum(a) / len(a)

    def gcd(self, x, y):
        if y == 0:
            return x
        else:
            return self.gcd(y, x % y)


"""ここからメインコード"""


def main():
    # 1文字に省略
    r, e, p = range, enumerate, print
    ip = IP()
    id = Idea()
    mod = 10 ** 9 + 7

    """この下から書いてね"""
    n = ip.I()
    a = ip.IL()
    flag = True
    ans = 0
    while flag:
        flag = False
        for j in r(n - 1, 0, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                flag = True
                ans += 1
    p(*a)
    p(ans)


main()

