
cnt = 0
SENTINEL = 2000000000

def merge(arr, length, left, mid, right):
#  n1 = mid - left
#  n2 = right - mid

    L = arr[left : mid]
    R = arr[mid : right]

    L.append(SENTINEL)
    R.append(SENTINEL)

    i, j = 0, 0
    for k in range(left, right):
        global cnt
        cnt += 1
        if (L[i] <= R[j]):
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1

def merge_sort(arr, length, left, right):
    if (left + 1 < right):
        mid = (left + right)//2
        merge_sort(arr, length, left, mid)
        merge_sort(arr, length, mid, right)
        merge(arr, n, left, mid, right)    

if __name__ == '__main__':
    n = int(input())
    S = list(map(int, input().split()))

    merge_sort(S, n, 0, n)
    print(' '.join(map(str, S)))
    print(cnt)

