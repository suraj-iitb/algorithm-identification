def counting_sort(a, b, k):
    c = [0 for _ in range(k+1)]
    n = len(a)

    for j in range(n):
        c[a[j]] += 1

    for i in range(1, k+1):
        c[i] += c[i-1]

    for j in range(n - 1, -1, -1):
        b[c[a[j]] - 1] = a[j]
        c[a[j]] -= 1


def print_list_split_whitespace(a):
    for x in a[:-1]:
        print(x, end=" ")
    print(a[-1])


n = int(input())
a = [int(x) for x in input().split()]
b = a.copy()
k = max(a)

counting_sort(a, b, k)

print_list_split_whitespace(b)
