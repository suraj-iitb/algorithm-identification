import sys

def merge(A, left, mid, right):
    L = A[left: mid] + [sys.maxsize]
    R = A[mid: right] + [sys.maxsize]
    i = j = count = 0
    k = left
    while k < right:
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        k += 1
    return count

def merge_sort(A, left, right):
    if right - left > 1:
        mid = (left + right) // 2
        lcost = merge_sort(A, left, mid)
        rcost = merge_sort(A, mid, right)
        tot = merge(A, left, mid, right)
        return tot + lcost + rcost
    else:
        return 0

if __name__ == '__main__':
    n = int(input())
    A = [int(i) for i in input().split()]
    count = merge_sort(A, 0, n)
    print(str(A).replace(',', '').replace('[', '').replace(']', ''))
    print(count)
