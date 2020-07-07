def insertion_sort(a, n):
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
        print_list_split_whitespace(a)


def print_list_split_whitespace(a):
    for x in a[:-1]:
        print(x, end=' ')
    print(a[-1])


n = int(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])

print_list_split_whitespace(a)
insertion_sort(a, n)
