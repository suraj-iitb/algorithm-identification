def insertionSort(lst, n):
    for i in range(1, n):
        v = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > v:
            lst[j+1] = lst[j]
            j = j - 1
        lst[j+1] = v
        print(" ".join([str(n) for n in lst]))


if __name__ == "__main__":
    n = int(input())
    lst = [int(n) for n in input().split()]
    print(" ".join([str(n) for n in lst]))
    insertionSort(lst, n)
