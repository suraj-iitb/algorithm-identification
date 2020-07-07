def countingsort(a, b, k):
    c = [0 for i in range(k)]
    for i in range(len(a)):
        c[a[i]] += 1
    for i in range(1,k):
        c[i] += c[i - 1]
    for i in range(len(a))[::-1]:
        b[c[a[i]] - 1] = a[i]
        c[a[i]] -= 1

n = int(input())
a = list(map(int, input().split()))
b = [0 for i in range(n)]
countingsort(a, b, max(a) + 1)
print(" ".join(map(str, b)))
