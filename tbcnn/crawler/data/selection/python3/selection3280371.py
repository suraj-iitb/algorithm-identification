import sys


def selection_sort(a, n):
    swap_count = 0
    for i in range(0, n):
        minj = min(range(i, n), key=a.__getitem__)
        if i != minj:
            a[i], a[minj] = a[minj], a[i]
            swap_count += 1
    return swap_count


n = int(sys.stdin.readline())
a = [int(v) for v in sys.stdin.readline().strip().split()]
count = selection_sort(a, n)

print(' '.join(map(str, a)))
print(count)
