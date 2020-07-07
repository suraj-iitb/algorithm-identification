def insertionSort(A, n, gap):
    cnt = 0
    for i in range(gap, n):
        v = A[i]
        j = i - gap
        while j >= 0 and A[j] > v:
            cnt += 1
            A[j + gap] = A[j]
            j = j - gap
        A[j + gap] = v
    return cnt


def shellSort(A, n):
    if len(A) == 1:
        print(1,1,0,A[0],sep='\n')
        exit()
    cnt = 0
    G = []
    m = 1
    while (3**m - 1) // 2 < n:
        G.append((3**m - 1) // 2)
        m += 1
    m -= 1
    print(m)
    for i in range(m):
        cnt += insertionSort(A, n, G[m - i - 1])
    print(*G[::-1])
    print(cnt)
    print(*A, sep='\n')

N = int(input())
A = list([int(input()) for i in range(N)])
shellSort(A, N)
