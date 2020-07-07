def selection_sort(a, n):
    cnt = 0
    for i in range(n):
        min_ind = i
        for j in range(i, n):
            if a[j] < a[min_ind]:
                min_ind = j
        if a[i] != a[min_ind]:
            a[i], a[min_ind] = a[min_ind], a[i]
            cnt += 1
    return a, cnt

n = int(input())
a = list(map(int, input().split()))
ans, cnt = selection_sort(a, n)
print(*ans)
print(cnt)
