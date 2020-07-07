N = int(input())
ary = [int(_) for _ in input().split()]


def insertion_sort(ary, verbose=True):

    for i in range(1, N):

        if verbose:
            print(' '.join([str(_) for _ in ary]))

        v = ary[i]
        j = i - 1

        while j >= 0 and ary[j] > v:
            ary[j + 1] = ary[j]
            j -= 1

        ary[j + 1] = v

    print(' '.join([str(_) for _ in ary]))


insertion_sort(ary)

