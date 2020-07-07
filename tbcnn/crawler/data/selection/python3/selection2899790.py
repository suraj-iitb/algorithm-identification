def selection_sort(a, n):
    counter = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            counter += 1
            tmp = a[i]
            a[i] = a[minj]
            a[minj] = tmp
    return counter


def print_list_split_whitespace(a):
    for x in a[:-1]:
        print(x, end=' ')
    print(a[-1])


n = int(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])

counter = selection_sort(a, n)
print_list_split_whitespace(a)
print(counter)
