def selection_sort(a, n):

    swap_count = 0
    for i in range(0, n):
        min_j = i
        for j in range(i, n):
            if a[j] < a[min_j]:
                min_j = j
        a[i], a[min_j] = a[min_j], a[i]
        if i != min_j:
            swap_count += 1

    print(' '.join(map(str, a)))
    print(swap_count)


def main():
    n = int(input())
    a = list(map(int, input().split(' ')))
    selection_sort(a, n)


if __name__ == "__main__":
    main()

