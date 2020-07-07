def bubble_sort(a, n):
    flag = True
    counter = 0
    while flag:
        flag = False
        for j in range(n - 1, 0, -1):
            if a[j] < a[j - 1]:
                counter += 1
                tmp = a[j]
                a[j] = a[j - 1]
                a[j - 1] = tmp
                flag = True
    return counter


def print_list_split_whitespace(a):
    for x in a[:-1]:
        print(x, end=' ')
    print(a[-1])


n = int(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])

counter = bubble_sort(a, n)
print_list_split_whitespace(a)
print(counter)
