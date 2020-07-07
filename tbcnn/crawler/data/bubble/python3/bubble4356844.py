def bubblesort(a, n):
    n_exchange = 0
    flag = True
    while flag:
        flag = False
        for j in range(n-1, 0, -1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                n_exchange += 1
                flag = True

    return a, n_exchange

n = int(input())
a = list(map(int, input().split()))

a_sort, n_exchange = bubblesort(a, n)

print(' '.join([str(x) for x in a_sort]))
print(n_exchange)

