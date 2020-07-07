def selectionSort(a, n):
    c = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if minj != i:
            c += 1

    return a, c

if __name__ == "__main__":
    n = int(input())
    a_l = [int(a) for a in input().split()]

    as_l, c = selectionSort(a_l, n)
    print(' '.join(map(str, as_l)))
    print(c)
