n = int(input())
l = list(map(int, input().split()))


def selectionSort(a, n):
    ans = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j

        a[i], a[minj] = a[minj], a[i]
        if i != minj:
            ans += 1

    print(*a)
    print(ans)


selectionSort(l, n)

