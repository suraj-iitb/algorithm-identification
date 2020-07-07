# coding=utf-8
def merge(a, left, mid, right):
    n1 = mid-left
    n2 = right - mid

    left_list = [a[left + i] for i in range(n1)]
    right_list = [a[mid + i] for i in range(n2)]
    left_list.append(1000000007)
    right_list.append(1000000007)

    i = 0
    j = 0
    ctr = 0
    for k in range(left, right):
        ctr += 1
        if left_list[i] <= right_list[j]:
            a[k] = left_list[i]
            i += 1
        else:
            a[k] = right_list[j]
            j += 1
    return ctr


def merge_sort(a, left, right, counter):
    if left+1 < right:
        mid = (left + right)//2
        counter1 = merge_sort(a, left, mid, counter)[1]
        counter2 = merge_sort(a, mid, right, counter)[1]
        counter += merge(a, left, mid, right)
        counter += counter1
        counter += counter2
    return a, counter


if __name__ == '__main__':
    n = int(input())
    S = list(map(int, input().split()))
    merge_counter = 0
    S, merge_counter = merge_sort(S[:], 0, len(S), merge_counter)

    print(' '.join(map(str, S)))
    print(merge_counter)
