def bubble_sort(array, n):
    flag = True
    count = 0
    while flag:
        flag = False
        for j in range(n - 1, 0, -1):
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
                flag = True
                count += 1
    return count


def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    count = bubble_sort(a, n)
    print(*a)
    print(count)


if __name__ == '__main__':
    main()

