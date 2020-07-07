# ALDS1_5_B Merge Sort
import sys
count = 0

def merge(A, left, mid, right):
    global count
    l = A[left: mid]
    r = A[mid: right]

    l.append(float('inf'))
    r.append(float('inf'))

    i = 0
    j = 0

    for k in range(left, right, 1):
        count += 1
        if l[i] <= r[j]:
            A[k] = l[i]
            i += 1
        else:
            A[k] = r[j]
            j += 1


def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)


n = int(input())
S = [int(i) for i in sys.stdin.readline().strip().split()]

merge_sort(S, 0, n)
print(' '.join(map(str, S)))
print(count)
