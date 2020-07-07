def insertionSort(table, g):
    global cnt
    for i in range(g, len(table)):
        v = table[i]
        j = i - g
        while j >= 0 and table[j] > v:
            table[j + g] = table[j]
            j = j - g
            cnt += 1
        table[j + g] = v


def shellSort(table):
    gap = [1]
    while gap[0] * 3 + 1 < len(table):
        gap.insert(0, (gap[0] * 3 + 1))
    for g in gap:
        insertionSort(table, g)
    return gap


n = int(input())
table = []
cnt =0
for i in range(n):
    table.append(int(input()))
gap = shellSort(table)
print(len(gap))
print(' '.join(map(str, gap)))
print(cnt)
print('\n'.join(map(str, table)))

