def selection_sort(a, n):
    cnt = 0
    for i in range(0, n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            tmp = a[i]
            a[i] = a[minj]
            a[minj] = tmp
            cnt += 1
    return a, cnt

a = []
n = int(input())
s = input()
a = list(map(int, s.split()))
a, cnt = selection_sort(a, n)
print(*a)
print(cnt)
