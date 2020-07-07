n = int(input())
s = list(map(int, input().split()))
k = max(s)
c = [0 for i in range(k+1)]
def counting_sort(a, k):
    global c
    b = [0 for i in range(len(a)+1)]
    for i in range(n):
        c[a[i]] += 1

    for i in range(1,k+1):
        c[i] = c[i] + c[i - 1]

    for i in reversed(range(n)):
        b[c[a[i]]] = a[i]
        c[a[i]] -= 1
    return b
res = counting_sort(s, k)[1:n+1]
print(*res)
#print(c)

