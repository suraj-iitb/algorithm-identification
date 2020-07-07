def bubbleSort(a, n):
    flag = True
    c = 0
    while flag:
        flag = False
        for j in reversed(range(1, n)):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                c += 1
                flag = True

    return a, c

if __name__ == "__main__":
    n = int(input())
    a_l = [int(a) for a in input().split()]

    as_l, c  = bubbleSort(a_l, n)
    print(' '.join(map(str, as_l)))
    print(c)
