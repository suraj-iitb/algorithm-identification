import sys
import operator
import collections


Card = collections.namedtuple('Card', ('suit', 'value'))


def partition(a, p, r):
    x = a[r].value
    i = p - 1
    for j in range(p, r):
        if a[j].value <= x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1


def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q - 1)
        quick_sort(a, q + 1, r)


n = int(sys.stdin.readline())
a = []
for _ in range(n):
    suit, value = sys.stdin.readline().split()
    a.append(Card(suit, int(value)))

stable = sorted(a, key=operator.itemgetter(1))
quick_sort(a, 0, n - 1)

print('Stable' if a == stable else 'Not stable')
for suit, value in a:
    print(f'{suit} {value}')

