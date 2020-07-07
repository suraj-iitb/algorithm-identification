def insertionSort(a, N, g, count):
    for i in range(g, N):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j -= g
            count += 1
        a[j+g] = v
    return count

def shellSort(a, N):
    count = 0
    G = []
    G.append(1)
    i = 0
    while G[i] <= N:
        G.append(3*G[i] + 1)
        i += 1
    del G[-1]
    m = len(G)
    for i in range(m):
        count = insertionSort(a, N, G[m-1-i], count)
    return G, count


if __name__ == "__main__":
    N = int(input())
    a = [int(input()) for _ in range(N)]
    answer = shellSort(a, N)
    print(len(answer[0]))
    print(*answer[0][::-1])
    print(answer[1])
    for x in a: print(x)

