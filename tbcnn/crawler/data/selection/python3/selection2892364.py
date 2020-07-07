N = int(input())
ary = [int(_) for _ in input().split()]


def selection_sort(ary, verbose=True):
    count = 0

    for i in range(0, N):
        minj = i

        for j in range(i, N):
            if ary[j] < ary[minj]:
                minj = j

        if i != minj:
            ary[i], ary[minj] = ary[minj], ary[i]
            count += 1

    print(' '.join([str(_) for _ in ary]))

    if verbose:
        print(count)


selection_sort(ary)

