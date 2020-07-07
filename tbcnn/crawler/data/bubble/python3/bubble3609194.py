
def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0

    flag = True
    while flag:
        flag = False
        for i in range(1, n):
            if a[i] < a[i-1]:
                a[i], a[i-1] = a[i-1], a[i]
                flag = True
                ans += 1
    print(*a)
    print(ans)


if __name__ == '__main__':
    main()
