def selectionSort(lst, n):
    cnt = 0
    for i in range(0, n):
        minj = i
        for j in range(i, n):
            if lst[j] < lst[minj]:
                minj = j

        if i != minj:
            tmp = lst[i]
            lst[i] = lst[minj]
            lst[minj] = tmp
            cnt += 1
    return (lst, cnt)


if __name__ == "__main__":
    n = int(input())
    lst = [int(n) for n in input().split()]
    result, cnt = selectionSort(lst, n)
    print(" ".join(str(n) for n in result))
    print(cnt)
