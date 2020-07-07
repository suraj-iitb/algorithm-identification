# -*- coding: utf-8 -*-


def selection_sort(n, a):
    cnt = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            tmp = a[minj]
            a[minj] = a[i]
            a[i] = tmp
            cnt += 1
    return a, cnt


if __name__ == '__main__':
    n = int(input())
    a = [int(n) for n in input().split()]
    ans, cnt = selection_sort(n, a)
    print(' '.join(map(str, ans)))
    print(cnt)
