def selection_sort(a, n):
    number = 0
    for i in range(n):
        min_index = a[i:].index(min(a[i:])) + i
        a[min_index], a[i] = a[i], a[min_index]
        if i != min_index:
            number += 1
    return number


n = int(input())
*ls, = map(int, input().split())
num = selection_sort(ls, n)
print(*ls)
print(num)

