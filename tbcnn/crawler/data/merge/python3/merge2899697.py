INF = 10**10


def merge(ary, left, mid, right):
    lry = ary[left:mid]
    rry = ary[mid:right]

    lry.append(INF)
    rry.append(INF)
    i = 0
    j = 0

    for k in range(left, right):
        if lry[i] <= rry[j]:
            ary[k] = lry[i]
            i += 1
        else:
            ary[k] = rry[j]
            j += 1

    return right - left


def merge_sort(ary, left, right):
    cnt = 0
    if left + 1 < right:
        mid = (left + right) // 2
        cnt += merge_sort(ary, left, mid)
        cnt += merge_sort(ary, mid, right)
        cnt += merge(ary, left, mid, right)
    return cnt


if __name__ == '__main__':
    n = int(input())
    ary = [int(_) for _ in input().split()]
    cnt = merge_sort(ary, 0, n)
    print(*ary)
    print(cnt)

