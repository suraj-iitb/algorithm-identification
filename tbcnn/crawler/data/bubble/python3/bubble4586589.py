def bubbleSort(table):
    swap_count = 0
    for nAchieve in range(len(table) - 1):
        for index in range(len(table) - 1, nAchieve, -1):
            if table[index] < table[index - 1]:
                table[index], table[index - 1] = table[index - 1], table[index]
                swap_count += 1
    return swap_count


def conversion(table):
    return ' '.join(map(str, table))


element = int(input())
table = list(map(int, input().split()))
swap_count = bubbleSort(table)
table = conversion(table)

print('{}\n{}'.format(table, swap_count))
