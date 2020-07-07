def main():
    N = int(input())
    a_lists = list(map(int, input().split()))
    cnt = 0
    for i in range(N):
        min_j = i
        for j in range(i, N):
            if a_lists[j] < a_lists[min_j]:
                min_j = j
        if min_j == i:
            continue
        a_lists[i], a_lists[min_j] = a_lists[min_j], a_lists[i]
        cnt += 1
    print(' '.join(map(str, a_lists)))
    print(cnt)


if __name__ == '__main__':
    main()

