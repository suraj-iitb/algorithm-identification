MAXVAL = 10000


def counting_sort(li):
    """Sort li by counting the number of occurrences of each
    element in li.
    All the elements in li are supposed to be 0..10000.

    >>> counting_sort([2, 5, 1, 3, 2, 3, 0])
    [0, 1, 2, 2, 3, 3, 5]
    """
    counter = [0] * (MAXVAL+1)

    for e in li:
        counter[e] += 1

    for i in range(1, MAXVAL+1):
        counter[i] += counter[i-1]

    result = [None] * len(li)
    for e in reversed(li):
        counter[e] -= 1
        result[counter[e]] = e

    return result


def run():
    _ = int(input())  # flake8: noqa
    xs = [int(i) for i in input().split()]

    print(" ".join([str(i) for i in counting_sort(xs)]))


if __name__ == '__main__':
    run()

