def counting_sort(a, b, k):
    c = [0 for _ in range(k + 1)]
    for i in range(len(a)):
        c[a[i]] += 1
    for i in range(1, len(c)):
        c[i] += c[i -1]
    for i in range(len(a) - 1, -1, -1):
        b[c[a[i]] - 1] = a[i]
        c[a[i]] -= 1

n = input()
a = list(map(int, input().split()))
b = [0 for _ in range(len(a))]
counting_sort(a, b, max(a))
print(*b)

