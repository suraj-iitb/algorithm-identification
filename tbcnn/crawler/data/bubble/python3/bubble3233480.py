def solve():
    _ = input()
    l = list(map(int, input().split()))
    count = 0
    is_sorted = True
    while is_sorted:
        is_sorted = False
        for i in range(len(l) - 1, 0, -1):
            if l[i] < l[i - 1]:
                l[i], l[i-1] = l[i-1], l[i]
                is_sorted = True
                count += 1

    print(' '.join(map(str, l)))
    print(count)


if __name__ == '__main__':
    solve()

