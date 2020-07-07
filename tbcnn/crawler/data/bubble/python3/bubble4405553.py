def bubbleSort(sort_list):
    flag = True
    count = 0
    while flag:
        flag = False

        for j in range(len(sort_list) - 1, 0, -1):
            if sort_list[j] < sort_list[j - 1]:
                tmp = sort_list[j]
                sort_list[j] = sort_list[j - 1]
                sort_list[j - 1] = tmp
                count += 1
                flag = True

    print(' '.join([str(i) for i in sort_list]))
    print(count)


if __name__ == "__main__":
    N = int(input())
    sort_list = [int(i) for i in input().split()]

    bubbleSort(sort_list)

