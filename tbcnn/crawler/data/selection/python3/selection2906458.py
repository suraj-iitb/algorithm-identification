def selection_sort(a):
    res = 0
    for i in range(len(a)):
        m = i
        for j in range(i, len(a)):
            if a[m] > a[j]:
                m = j
        if m != i:
            res += 1
            a[i], a[m] = a[m], a[i]
    return res


def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = selection_sort(a)
    print(' '.join(map(str, a)))
    print(ans)


if __name__ == '__main__':
    main()
