def selection_sort(array, n):
    count = 0
    for i in range(n):
        index_min = i
        for j in range(i, n):
            if array[j] < array[index_min]:
                index_min = j
        if array[index_min] < array[i]:
            array[i], array[index_min] = array[index_min], array[i]
            count += 1
    return count


def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    count = selection_sort(a, n)
    print(*a)
    print(count)


if __name__ == '__main__':
    main()

