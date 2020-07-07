def selection_sort(a, n):
    sw_num = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            tmp = a[i]
            a[i] = a[minj]
            a[minj] = tmp
            sw_num += 1

    return sw_num


n = int(input())
a = [int(i) for i in input().split()]

sw_num = selection_sort(a, n)

print(' '.join([str(i) for i in a]))
print(sw_num)
