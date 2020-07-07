def printTable(table):
    for i in range(len(table)):
        print(table[i], end='')
        if i != len(table)-1:
            print(' ', end='')
    print()


def insertionSort(table):
    for i in range(1, len(table)):
        min = table[i]
        j = i - 1
        while j >= 0 and min < table[j]:
            table[j + 1] = table[j]
            table[j] = min
            j += -1
        printTable(table)


number = int(input())
table = list(map(int, input().split()))
printTable(table)
insertionSort(table)
