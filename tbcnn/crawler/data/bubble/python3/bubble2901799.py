N = int(input())
ary = [int(_) for _ in input().split()]


def bubble_sort(ary, verbose=True):
    flag = True
    count = 0
    i = 0
    while flag:
        flag = False
        for j in range(N - 1, i, -1):
            if ary[j] < ary[j - 1]:
                ary[j], ary[j - 1] = ary[j - 1], ary[j]
                flag = True
                count += 1
        i += 1

    print(' '.join([str(_) for _ in ary]))

    if verbose:
        print(count)


bubble_sort(ary)

