def selectionSort(table):
    swap_count = 0
    for nAchieve in range(len(table)):
        min_index = nAchieve
        for i in range(nAchieve, len(table)):
            if table[i] < table[min_index]:
                min_index = i
        if min_index != nAchieve:
            table[min_index], table[nAchieve] = table[nAchieve], table[min_index]
            swap_count += 1
    return swap_count


element = int(input())
table = list(map(int, input().split()))
swap_count = selectionSort(table)

print(' '.join(map(str, table)))
print(swap_count)

