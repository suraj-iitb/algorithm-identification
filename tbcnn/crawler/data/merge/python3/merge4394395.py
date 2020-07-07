n = int(input())
S = list(map(int, input().split()))
c = 0


def merge(left, mid, right):
    global c
    L = S[left:mid] + [float('inf')]
    R = S[mid:right] + [float('inf')]
    i, j = 0, 0
    for k in range(left, right):
        if L[i] <= R[j]:
            S[k] = L[i]
            i += 1
        else:
            S[k] = R[j]
            j += 1
    c += right - left


def merge_sort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(left, mid)
        merge_sort(mid, right)
        merge(left, mid, right)


merge_sort(0, n)

print(*S)
print(c)

