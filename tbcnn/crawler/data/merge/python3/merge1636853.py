from collections import deque

INFTY = 1e9 + 1


def merge(a, l, m, r):
    global cnt
    ll = deque(a[l:m])
    rl = deque(a[m:r])
    ll.append(INFTY)
    rl.append(INFTY)
    for k in range(l, r):
        a[k] = (ll if ll[0] < rl[0] else rl).popleft()
    cnt += r - l


def merge_sort(a, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m, r)
        merge(a, l, m, r)


n, a, cnt = int(input()), list(map(int, input().split())), 0
merge_sort(a, 0, n)
print(*a)
print(cnt)
