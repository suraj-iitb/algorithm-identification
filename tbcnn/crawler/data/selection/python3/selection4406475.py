def selectionSort(sort_list):
    count = 0

    for i in range(0, len(sort_list)):
        minj = i

        for j in range(i, len(sort_list)):
            if sort_list[j] < sort_list[minj]:
                minj = j

        if minj != i:
            tmp = sort_list[i]
            sort_list[i] = sort_list[minj]
            sort_list[minj] = tmp
            count += 1

    print(' '.join([str(i) for i in sort_list]))
    print(count)


if __name__ == "__main__":
    N = int(input())
    sort_list = [int(i) for i in input().split()]

    selectionSort(sort_list)

