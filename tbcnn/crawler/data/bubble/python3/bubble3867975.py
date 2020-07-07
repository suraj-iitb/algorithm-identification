def bubble_sort(a, n):
    # N個の要素を含む0-オリジナルの配列A
    cnt = 0
    flag = True
    while flag:
        flag = False
        for j in reversed(range(1, n)):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                cnt += 1
                flag = True
    print(" ".join([str(x) for x in a]))
    print(cnt)


def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    bubble_sort(a, n)


if __name__ == '__main__':
    main()

