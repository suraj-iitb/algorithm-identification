n = int(input())
a = list(map(int, input().split()))


def countingsort(a, k):
    c = [0 for i in range(k+1)]
    b = [0 for i in range(n)]

    for j in range(n):
        c[a[j]] += 1

    for i in range(k):
        c[i+1] += c[i]

    for j in reversed(range(n)):
        b[c[a[j]]-1] = a[j]
        c[a[j]] -= 1

    return b

b = countingsort(a, 10000)
print(*b)

