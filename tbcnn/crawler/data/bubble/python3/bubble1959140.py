def bubbleSort(a, n):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(n - 1, 0, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                count += 1
                flag = 1
    return count


def main():
    n = int(input())
    a = [int(x) for x in input().split(' ')]
    count = bubbleSort(a, n)
    print(' '.join([str(x) for x in a]))
    print(count)

if __name__ == '__main__':
    main()
