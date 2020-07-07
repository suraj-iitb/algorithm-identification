cnt = 0


def insSort(A, n, g):
    global cnt

    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v


def shellSort(A, n):
    G = []
    i = 1
    while True:
        G.append(i)
        i = i * 3 + 1
        if i > n - 2:
            break
    G.reverse()

    print(len(G))
    print(*G)

    for i in G:
        insSort(A, n, i)


n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))

shellSort(arr, n)

print(cnt)

for s in arr:
    print(s)

