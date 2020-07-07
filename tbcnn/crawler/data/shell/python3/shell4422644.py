
def insertationSort(sort_list, n, g):
    cnt = 0
    for i in range(g, n):
        v = sort_list[i]
        j = i - g

        while j >= 0 and sort_list[j] > v:
            sort_list[j + g] = sort_list[j]
            j -= g
            cnt += 1
        sort_list[j + g] = v

    return cnt


def shellSort(sort_list, n):

    cnt = 0

    G = [1]

    while True:
        if G[len(G)-1] * 3 + 1 <= n:
            G.append(G[len(G)-1] * 3 + 1)
        else:
            break

    m = len(G)


    for i in G[::-1]:
        cnt += insertationSort(sort_list, n, i)

    print(m)
    print(' '.join([str(i) for i in G[::-1]]))
    print(cnt)
    for ans in sort_list:
        print(ans)


if __name__ == "__main__":
    N = int(input())

    sort_list = list()

    for _ in range(N):
        sort_list.append(int(input()))

    shellSort(sort_list, N)
