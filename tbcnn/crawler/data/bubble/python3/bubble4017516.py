def bubble_sort(a, n):

    swap_count = 0
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in range(n-1, i, -1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                flag = 1
                swap_count += 1
        i += 1

    print(' '.join(map(str, a)))
    print(swap_count)


def main():
    n = int(input())
    a = list(map(int, input().split(' ')))
    bubble_sort(a, n)


if __name__ == "__main__":
    main()

