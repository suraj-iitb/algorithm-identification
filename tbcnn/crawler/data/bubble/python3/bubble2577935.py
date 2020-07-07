def bubbleSort(lst, n):
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in range(n-1, 0, -1):
            if lst[j] < lst[j-1]:
                tmp = lst[j]
                lst[j] = lst[j-1]
                lst[j-1] = tmp
                flag = 1
                i = i + 1
    print(" ".join([str(n) for n in lst]))
    print(i)


if __name__ == "__main__":
    n = int(input())
    lst = [int(n) for n in input().split()]
    bubbleSort(lst, n)
