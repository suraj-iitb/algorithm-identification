def insertion_sort(array, n):
    for i in range(1, n):
        v = array[i]
        j = i - 1
        while j >= 0 and v < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = v
        print(*array)


def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    print(*a)
    insertion_sort(a, n)


if __name__ == '__main__':
    main()


