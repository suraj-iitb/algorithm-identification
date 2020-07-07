def insertion_sort(alist):
    """sort alist by insertion sort.
    print the intermediate sequence for each step.

    >>> insertion_sort([5, 2, 4, 6, 1, 3])
    5 2 4 6 1 3
    2 5 4 6 1 3
    2 4 5 6 1 3
    2 4 5 6 1 3
    1 2 4 5 6 3
    1 2 3 4 5 6
    [1, 2, 3, 4, 5, 6]
    """
    for i, key in enumerate(alist):
        for j in reversed(range(i)):
            if alist[j] <= key:
                alist[j+1] = key
                break
            else:
                alist[j+1] = alist[j]
        else:
            alist[0] = key
        print(" ".join([str(i) for i in alist]))

    return alist


def run():
    _ = int(input())  # flake8: noqa
    nums = [int(i) for i in input().split()]

    insertion_sort(nums)


if __name__ == '__main__':
    run()

