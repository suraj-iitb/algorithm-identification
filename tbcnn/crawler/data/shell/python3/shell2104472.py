def insertion_sort(array, size, gap=1):
    """ AOJ??¬??¶?????¬???
    http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=ALDS1_1_A

    :param array: ?????????????±??????????
    :return: ?????????????????????
    """
    global Count

    for i in range(gap, len(array)):  # i????¬??????????????????????????????????
        v = array[i]  # ?????¨?????\???????????¨????????????????????????????????´???
        j = i - gap
        while j >= 0 and array[j] > v:
            array[j + gap] = array[j]
            j = j - gap
            Count += 1
        array[j + gap] = v
    return array

def shell_sort(array, n):
    Count = 0
    G = calc_gap(n)
    m = len(G)
    print(m)
    print(' '.join(map(str, G)))
    for i in range(0, m):
        insertion_sort(array, n, G[i])


def calc_gap(n):
    results = [1]
    while results[-1] < n:
        results.append(3 * results[-1] + 1)
    if len(results) > 1:
        results = results[:-1]
    results.sort(reverse=True)
    return results


Count = 0
if __name__ == '__main__':
    # ??????????????\???
    # data = [5, 1, 4, 3, 2]
    data = []
    num = int(input())
    for i in range(num):
        data.append(int(input()))

    # ???????????????
    shell_sort(data, len(data))

    # ???????????¨???
    print(Count)
    for i in data:
        print(i)
