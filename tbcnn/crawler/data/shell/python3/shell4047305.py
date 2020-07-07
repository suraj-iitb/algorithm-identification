exchange_cnt = 0

def insertion_sort(w_list, g):
    """一般化した Insertion ソート

    通常の Insertion ソートは gap が 1 固定だが、ここでは、
    gap を引数 g で指定できる。

    当然、g < len(w_list) でないといけない。
    """
    global exchange_cnt
    N = len(w_list)
    for i in range(g, N):
        v = w_list[i]
        j = i - g
        while j >= 0 and w_list[j] > v:
            w_list[j+g] = w_list[j]
            j -= g
            exchange_cnt += 1
        w_list[j+g] = v


def make_gap_sequence(n):
    """gap sequence を作成

    とりあえず、Wiki にのっていたやり方のひとつを採用。
    N ^ 1.5 のオーダーになるという。
    """
    seq = []
    k = 1
    while True:
        gap = 2 ** k - 1
        if gap > n:
            break
        seq.append(gap)
        k += 1
    seq.reverse()   # in place なので効率が良い。
    return seq

def make_gap_sequence_2(n):
    """もうひとつの gap sequence の作成方法

    Wiki にのっていた Shell によるオリジナルの方法。
    これだと最悪の場合、N ^ 2 のオーダーになってしまうようだ。
    """
    seq = []
    k = 1
    while True:
        gap = n // (2 ** k)
        if gap <= 1:
            break
        seq.append(gap)
        k += 1
    seq.append(1)
    return seq



def shell_sort(w_list):
    N = len(w_list)

    # N から gap sequence を決める。
    # どう決めるかで効率が変わってくるのだが、どう決めるかは難問。
    # gap_sequence = make_gap_sequence(N)
    gap_sequence = make_gap_sequence_2(N)

    for g in gap_sequence:
        insertion_sort(w_list, g)
    
    return gap_sequence


n = int(input())
w_list = []
for _ in range(n):
    w_list.append(int(input()))

gap_seq = shell_sort(w_list)

print(len(gap_seq))
print(*gap_seq)
print(exchange_cnt)
for i in w_list:
    print(i)

