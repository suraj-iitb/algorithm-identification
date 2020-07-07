def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0

    for i in range(n):
        tmp = i
        for j in range(i, n):
            if a[j] < a[tmp]:
                tmp = j
        if i != tmp:
            a[i], a[tmp] = a[tmp], a[i]
            ans += 1

    print(*a)
    print(ans)


if __name__ == '__main__':
    main()
