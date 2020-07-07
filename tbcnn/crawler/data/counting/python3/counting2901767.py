def counting_sort(ary, bry, k):
    cry = [0 for i in range(k)]

    for j in range(n):
        cry[ary[j]] += 1

    for i in range(1, k):
        cry[i] = cry[i] + cry[i - 1]

    for j in range(n - 1, -1, -1):
        bry[cry[ary[j]] - 1] = ary[j]
        cry[ary[j]] -= 1

if __name__ == '__main__':
    n = int(input())
    ary = [int(_) for _ in input().split()]
    bry = [0 for i in range(n)]
    counting_sort(ary, bry, 10 ** 5)
    print(*bry)

