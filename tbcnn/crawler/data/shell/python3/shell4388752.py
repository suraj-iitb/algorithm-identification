n = int(input())
arr = [int(input()) for _ in range(n)] 

def insertionSort(arr, n, g):
    cnt = 0
    for i in range(g, n):
        key = arr[i]
        j = i - g
        while j >= 0 and arr[j] > key:
            arr[j + g] = arr[j]
            j -= g
            cnt += 1
        arr[j + g] = key
    return cnt

def shellSort(arr, n):
    G = []
    g = 1
    cnt = 0
    while g < n or g == 1:
        G.append(g)
        g = 3*g + 1
    G = G[::-1]
    print(len(G))
    for i in range(len(G)):
        cnt += insertionSort(arr, n, G[i])
    print(*G)
    print(cnt)
    for a in arr:
        print(a)

shellSort(arr, n)
