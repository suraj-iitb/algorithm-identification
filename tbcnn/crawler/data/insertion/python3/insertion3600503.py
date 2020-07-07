def main():
    N = int(input())
    L = list(map(int, input().split()))

    for i in range(1, N):
        print(*L)
        tmp = L[i]
        j = i
        while j > 0 and L[j-1] > tmp:
            L[j] = L[j-1]
            j -= 1
        L[j] = tmp

    print(*L)


if __name__ == '__main__':
    main()
