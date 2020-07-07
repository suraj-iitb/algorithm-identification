n = int(input())
l = list(map(int, input().split()))


def bubbleSort(a, n):
    flag = 1
    ans = 0
    while flag:
        flag = 0
        for j in range(n-1, 0, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                flag = 1
                ans += 1

    print(*a)
    print(ans)


bubbleSort(l, n)

