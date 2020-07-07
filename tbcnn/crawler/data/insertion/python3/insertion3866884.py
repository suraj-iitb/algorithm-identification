def insertion_sort(a, n):   # N個の要素を含む0-オリジンの配列A
    for i in range(n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        output(a)
    return a


def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    insertion_sort(a, n)


def output(int_arr):
    print(" ".join([str(x) for x in int_arr]))


if __name__ == '__main__':
    main()

