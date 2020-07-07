def insertSort(input_list):
    print(' '.join([str(i) for i in input_list]))
    for i in range(1, len(input_list)):
        tmp = input_list[i]
        j = i - 1

        while j >= 0 and input_list[j] > tmp:
            input_list[j + 1] = input_list[j]
            j -= 1
            input_list[j + 1] = tmp

        print(' '.join([str(i) for i in input_list]))


if __name__ == '__main__':
    N = int(input())

    L = input()
    input_list = [int(i) for i in L.split()]
    insertSort(input_list)

