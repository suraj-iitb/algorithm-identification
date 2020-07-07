k = 10000
c = [0] * (k + 1)


def countingSort(a, b):
    global k
    n = len(a) - 1
    for i in range(k + 1):
        c[i] = 0
    for j in range(n):
        c[a[j + 1]] += 1

    #print(c)

    for i in range(1, k + 1):
        c[i] = c[i] + c[i - 1]

    #print(c)
    for j in range(n):
        #print(a[j], c[a[j]])
        b[c[a[j + 1]]] = a[j + 1]
        c[a[j + 1]] -= 1


n = int(input())
*a, = map(int, input().split())
a.insert(0, 0)
b = [0] * (n + 1)

countingSort(a, b)
b.pop(0)
print(" ".join([str(v) for v in b]))
