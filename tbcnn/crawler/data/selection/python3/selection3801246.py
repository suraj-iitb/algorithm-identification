def main():
    n = int(input())
    a = list(map(int, input().split(' ')))
    c = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if a[i] != a[minj]:
            a[i], a[minj] = a[minj], a[i]
            c += 1
    print(' '.join(list(map(str, a))))
    print(c)


if __name__ == '__main__':
    main()
