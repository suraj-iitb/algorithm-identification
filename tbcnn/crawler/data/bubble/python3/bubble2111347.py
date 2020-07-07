# -*- coding: utf-8 -*-


def bubble_sort(n, a):
    cnt = 0
    flag = True
    while flag:
        flag = False
        for i in reversed(range(n)):
            if i is 0: break
            if a[i] < a[i - 1]:
                tmp = a[i]
                a[i] = a[i - 1]
                a[i - 1] = tmp
                flag = True
                cnt += 1
    return a, cnt


if __name__ == '__main__':
    n = int(input())
    a = [int(n) for n in input().split()]
    ans = bubble_sort(n, a)
    print(' '.join(map(str, ans[0])))
    print(ans[1])
