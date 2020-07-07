def selectionSort(a, n):
    count = 0
    for i in range(0, n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if i != minj:
            count += 1
    return count


def main():
    n = int(input())
    a = [int(x) for x in input().split(' ')]
    count = selectionSort(a, n)
    print(' '.join([str(x) for x in a]))
    print(count)


if __name__ == '__main__':
    main()
