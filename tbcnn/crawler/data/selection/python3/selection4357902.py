def selectionsort(a, n):
    n_exchange = 0
    for i in range(0, n):
        min_j = i
        for j in range(i, n):
            if a[j] < a[min_j]:
                min_j = j

        if a[i] != a[min_j]:
            n_exchange += 1

        a[i], a[min_j] = a[min_j], a[i]

    return a, n_exchange


n = int(input())
a = list(map(int, input().split()))

sorted_a, n_exchange = selectionsort(a, n)

print(' '.join([str(x) for x in sorted_a]))
print(n_exchange)

