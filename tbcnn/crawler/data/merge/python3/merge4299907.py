def merge(arr, left: int, mid: int, right: int) -> int:
    n1 = mid - left
    n2 = right - mid
    L = [arr[left + i] for i in range(n1)]
    R = [arr[mid + i] for i in range(n2)]
    L.append(10 ** 9)
    R.append(10 ** 9)
    i = 0
    j = 0
    cnt = 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
    return cnt

def merge_sort(arr, left: int, right: int) -> int:
    cnt = 0
    if left + 1 < right:
        mid = (left + right) // 2
        cnt += merge_sort(arr, left, mid)
        cnt += merge_sort(arr, mid, right)
        cnt += merge(arr, left, mid, right)
    return cnt

n = int(input())
S = list(map(int, input().split()))
cnt = merge_sort(S, 0, n)
print(*S)
print(cnt)
