def do_selection_sort(data, size):
    assert size == len(data), "data size error"
    swap_count = 0
    for i in range(size):
        minj = i
        for j in range(i, size):
            if data[j] < data[minj]:
                minj = j
        temp = data[i]
        data[i] = data[minj]
        data[minj] = temp
        if data[i] != data[minj]:
            swap_count += 1
    return swap_count


if __name__ == '__main__':
    # ??????????????\???
    num = int(input())
    data = [int(x) for x in input().split(' ')]
    #data = [5, 6, 4, 2, 1, 3]
    #data = [5, 2, 4, 6, 1, 3]

    # ???????????????
    result = do_selection_sort(data, num)

    # ???????????????
    print('{0}'.format(' '.join(map(str, data))))
    print('{0}'.format(result))
