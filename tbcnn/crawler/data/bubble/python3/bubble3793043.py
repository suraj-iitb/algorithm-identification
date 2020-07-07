def main():
    n = int(input())
    a = list(map(int, input().split(' ')))
    c = 0
    flag = 1
    while flag:
        flag = 0
        j = 0
        for i in range(n-1, j, -1):
            if a[i] < a[i-1]:
                a[i], a[i-1] = a[i-1], a[i]
                c += 1
                flag = 1
        j -= 1
    print(' '.join(map(str, a)))
    print(c)


if __name__ == '__main__':
    main()
