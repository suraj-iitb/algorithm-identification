# ALDS1_2_D - Shell Sort
def insertion_sort(g: int) -> None:
    global cnt
    for i in range(g, N):
        x = A[i]
        j = i - g
        while j >= 0 and A[j] > x:
            A[j + g] = A[j]
            j -= g
            cnt += 1
        A[j + g] = x


def main():
    global N, A, cnt
    N, *A = map(int, open(0).read().split())
    # shell sort
    G, x = [1], 1  # gap
    while 3 * x + 1 < N:
        x = 3 * x + 1
        G += [x]
    cnt = 0
    for g in G[::-1]:
        insertion_sort(g)
    print(len(G))
    print(*G[::-1])
    print(cnt)
    print(*A, sep="\n")


if __name__ == "__main__":
    main()
