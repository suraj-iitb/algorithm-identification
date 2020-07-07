def solve():
    size = int(input())
    array = list(map(int, input().split()))
    SelectionSort(array, size)


def SelectionSort(array, size):
    swap_count = 0
    for i in range(0, size, 1):
        minj = i
        for j in range(i, size, 1):
            if array[j] < array[minj]:
                minj = j
        if array[i] is not array[minj]:
            array[i], array[minj] = array[minj], array[i]
            swap_count += 1
    print(' '.join(map(str, array)))
    print(swap_count)


if __name__ == '__main__':
    solve()

