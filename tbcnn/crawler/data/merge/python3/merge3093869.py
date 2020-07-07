from collections import deque


def merge(a, l, m, r):
    global c
    ll = deque(a[l:m])
    rl = deque(a[m:r])
    ll.append(10e10)
    rl.append(10e10)
    for k in range(l, r):
        a[k] = (ll if ll[0] < rl[0] else rl).popleft()
    c += r - l


def merge_sort(a, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m, r)
        merge(a, l, m, r)


if __name__ == '__main__':
    n, a, c = int(input()), list(map(int, input().split())), 0
    merge_sort(a, 0, n)
    print(*a)
    print(c)

