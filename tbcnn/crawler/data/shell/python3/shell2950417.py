def insertionSort(arr, N, g):
    cnt = 0
    for i in range(g, N):
        tmp = arr[i]
        j = i - g
        while(j >= 0 and arr[j] > tmp):
            arr[j + g] = arr[j]
            j -= g
            cnt += 1
        arr[j + g] = tmp
    return cnt


def shellSort(arr, N):
    G = []
    h = 0
    m = 0
    while h <= N / 9:
        h = 3 * h + 1
        G.append(h)
        m += 1
    G = G[::-1]

    cnt = sum([insertionSort(arr, N, g) for g in G])
    return (cnt, G)


N = int(input())
arr = [int(input()) for i in range(N)]

(cnt, G) = shellSort(arr, N)
print(len(G))
print(' '.join(map(str, G)))
print(cnt)
print('\n'.join(map(str, arr)))

