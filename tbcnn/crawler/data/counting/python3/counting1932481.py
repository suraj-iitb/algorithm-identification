def countingsort(a, n):
    c = [0]*10001

    for i in range(n):
        c[a[i]] += 1

    for j in range(1, 10001):
        c[j] += c[j - 1]

    b = [0]*(n+1)

    for k in range(n, 0, -1):
        b[c[a[k-1]]] = a[k-1]
        c[a[k-1]] -= 1

    return b[1:]


n = int(input())
a = list(map(int, input().split()))
print(*countingsort(a, n))
