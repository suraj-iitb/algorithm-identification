def insertionSort(A, n, g, count):
    Acopy = A.copy()
    for i in range(g, n):
        v = Acopy[i]
        j = i - g
        while (j >= 0) and (Acopy[j] > v):
            Acopy[j + g] = Acopy[j]
            j = j - g
            count += 1
        Acopy[j + g] = v
    return Acopy, count

def shellSort(A, n):
    #Gを作成
    G = [1]
    h = 4
    while h < n:
        G.append(h)
        h = 3 * h + 1
    Gr = G.copy()
    Gr.reverse()
    count = 0
    #Gの各要素を使ってSort
    for g in Gr:
        A, count = insertionSort(A, n, g, count)
    return A, Gr, count

n = int(input())
q = 0
A = []
while q < n:
    A.append(int(input()))
    q += 1
A, G, count = shellSort(A, n)
ans = str(len(G)) + '\n' + ' '.join(map(str, G)) + '\n' + str(count) + '\n'
ans += '\n'.join(map(str, A))
print(ans)
