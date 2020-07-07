
from typing import List, Callable
# verified @AOJ ALDS1_6_A
# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=jp
def counting_sort_destructive(L: List[int], k: int, key: Callable[[int], int] =lambda x: x) -> None:
    """
    counting_sort() の破壊関数版

    Args:
        L (list)
        k (int): L の要素は 0 to k であると仮定する
        key (function): key が指定されている場合、key を L の各要素に適用してからソートを行う

    Raises:
        ValueError: L の要素のいずれかが 0 <= x <= k を満たしていなかった場合

    Examples:
        >>> seq = [1, 3, 5, 10, 4, 6, 15, 7, 2, 0] 
        >>> counting_sort_destructive(seq, 15)    # 0 to 15
        >>> seq
        [0, 1, 2, 3, 4, 5, 6, 7, 10, 15]
    """
    if any(map(lambda x: key(x) < 0 or key(x) > k, L)):
        raise ValueError(f"counting_sort_destructive(): key(x) (x: element of L) should be 0 <= key(x) <= k. got k: {k}")

    n = len(L)
    accum_sum_memo = [0] * (k + 1)    # 0 to k なので

    for i in range(n):
        accum_sum_memo[key(L[i])] += 1
    for i in range(1, k+1):
        accum_sum_memo[i] += accum_sum_memo[i-1]
    
    tmp = tuple(L)    # もとの L のメモは変更されてはならない！
    for j in range(n-1, -1, -1):
        L[accum_sum_memo[key(tmp[j])] - 1] = tmp[j]
        accum_sum_memo[key(tmp[j])] -= 1    # 同じ値のものが来た時、一つ前の位置におさまるように調節してやる



# partially verified @AOJ ALDS1_6_A
# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=jp
def radix_sort(L: List[int], bucket_bit_size: int=8) -> None:
    """
    bucket_size = 2 ** bucket_bit_size とする (除算を避けビットシフトのみで実装するため、bucket_size は 2 の冪を仮定している)
    O(digit_length * (n + bucket_size)) で L を安定的かつ破壊的に基数ソートする (digit_length = log(n, bucket_size) である)
    
    Args:
        L (list)
        bucket_bit_size (int): L の各値を何 bit ごとに分けて基数ソートを行うかの値
    
    Raises:
        ValueError: L に負の値が含まれているとき

    Examples:
        >>> seq = [4321, 5500, 8686, 5586, 1234, 1235, 0, 24, 7, 1000000007]
        >>> radix_sort(seq, bucket_bit_size=8)
        >>> seq
        [0, 7, 24, 1234, 1235, 4321, 5500, 5586, 8686, 1000000007]
    """
    if any(map(lambda x: x < 0, L)):
        raise ValueError(f"radix_sort(): element of L should be positive. got L: {L}")
    if L:
        M = max(L)
        # 各整数を bucket_bit_size ビットごとに区切ると最大で何個のかたまりになりうるか
        max_digit_chank = (M.bit_length() + bucket_bit_size - 1) // bucket_bit_size
        # bucket_bit_size ビット分が 1 埋めされた bit mask
        mask = (1 << bucket_bit_size) - 1    # bit shift は +, - より優先度が低いので注意
        for i in range(max_digit_chank):
            key_func = lambda x: (x >> (i * bucket_bit_size)) & mask
            counting_sort_destructive(L, mask, key_func)




if __name__ == "__main__":
    n = int(input())
    L = list(map(int, input().split()))
    radix_sort(L, 16)
    print(*L, sep=' ')
