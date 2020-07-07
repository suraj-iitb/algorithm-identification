#!/usr/bin/env python


def selectionSort(line, size):
    """Rerutn sorted list.

    >>> selectionSort([1, 2, 3, 4], 4)
    ([1, 2, 3, 4], 0)

    >>> selectionSort([5,6,4,2,1,3], 6)
    ([1, 2, 3, 4, 5, 6], 4)
    """
    count = 0
    for i in range(0, size):
        minj = i
        for j in range(i, size):
            if line[j] < line[minj]:
                minj = j
        if line[i] != line[minj]:
            tmp = line[i]
            line[i] = line[minj]
            line[minj] = tmp
            count += 1
    return line, count


def main():
    size = int(input())
    line = list(map(int, input().split()))
    ans_list, count = selectionSort(line, size)
    ans = " ".join(map(str, ans_list))
    print(ans)
    print(count)


if __name__ == '__main__':
    import doctest
    doctest.testmod()
    main()
