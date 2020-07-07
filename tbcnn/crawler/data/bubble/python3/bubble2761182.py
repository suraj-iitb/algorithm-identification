def bubble_sort(alist):
    """Sort alist by bubble sort.
    Returns (number of swap operations, sorted list)

    >>> bubble_sort([5, 3, 2, 4, 1])
    ([1, 2, 3, 4, 5], 8)
    """
    size = len(alist)
    count = 0

    for i in range(size-1):
        for j in reversed(range(i+1, size)):
            if alist[j] < alist[j-1]:
                count += 1
                alist[j-1], alist[j] = alist[j], alist[j-1]

    return (alist, count)


def run():
    _ = int(input()) # flake8: noqa
    nums = [int(i) for i in input().split()]

    (sorted_list, num_swap) = bubble_sort(nums)

    print(" ".join([str(i) for i in sorted_list]))
    print(num_swap)


if __name__ == '__main__':
    run()
