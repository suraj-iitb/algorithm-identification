def selection_sort(alist):
    """Sort alist by selection sort.
    Returns the sorted list and number of swap operation.

    >>> selection_sort([5, 6, 4, 2, 1, 3])
    ([1, 2, 3, 4, 5, 6], 4)
    """
    size = len(alist)
    c = 0

    for i in range(size):
        mini = i
        for j in range(i, size):
            if alist[mini] > alist[j]:
                mini = j

        if i != mini:
            alist[i], alist[mini] = alist[mini], alist[i]
            c += 1

    return (alist, c)


def run():
    _ = int(input()) # flake8: noqa
    nums = [int(i) for i in input().split()]

    (sortednums, count) = selection_sort(nums)

    print(" ".join([str(i) for i in sortednums]))
    print(count)


if __name__ == '__main__':
    run()

