def insertionSortForShell(lst, n, g):
    cnt = 0
    for i in range(g, n):
        v = lst[i]
        j = i - g
        while j >= 0 and lst[j] > v:
            lst[j+g] = lst[j]
            j = j - g
            cnt += 1
        lst[j+g] = v
    return cnt


def cleate_split_lst(n):
    lst = []
    while 1:
        n = int(n/2)
        if n <= 1:
                lst.append(1)
                break
        else:
                lst.append(n)
    return lst


def shellSort(lst, n):
    cnt = 0
    G = cleate_split_lst(n)

    for i in range(0, len(G)):
        cnt += insertionSortForShell(lst, n, G[i])

    print(len(G))
    print(" ".join([str(g) for g in G]))
    print(cnt)
    for n in lst:
        print(n)


if __name__ == "__main__":
    n = int(input())
    lst = []
    for i in range(0, n):
        lst.append(int(input()))
    shellSort(lst, n)
