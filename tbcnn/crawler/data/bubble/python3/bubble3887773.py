def pintarr(arr):
    arr = [str(c) for c in arr]
    print(' '.join(arr))


def bub_sort(it, key):
    count = 0
    for start_ind in range(len(it)):
        for target_ind in range(len(it)-1, start_ind, -1):
            if it[target_ind] < it[target_ind-1]:
                it[target_ind], it[target_ind-1] = it[target_ind-1], it[target_ind],
                count += 1
    pintarr(it)
    print(count)


if __name__ == '__main__':

    t = int(input())
    a = input()
    a = [int(c) for c in a.split(' ')]
    bub_sort(a, t)

