# def merge(arr, l, mid, r):
#     L = [arr[i] for i in range(l, mid)]
#     R = [arr[i] for i in range(mid, r)]
#     L.append(int(1e9 + 10))
#     R.append(int(1e9 + 10))
#     i, j = 0, 0
#     cnt = 0
#     for k in range(l, r):
#         if L[i] <= R[j]:
#             arr[k] = L[i]
#             i += 1
#         else:
#             arr[k] = R[j]
#             j += 1
#         cnt += 1
#     return cnt

# def mergeSort(arr, l, r):
#     cnt = 0
#     if l + 1 < r:
#         mid = (l + r) >> 1
#         cnt += mergeSort(arr, l, mid)
#         cnt += mergeSort(arr, mid, r)
#         cnt += merge(arr, l, mid, r)
#     return cnt

# triky

def count(l, r):
    cnt = 0
    if l + 1 < r:
        mid = (l + r) >> 1
        cnt += count(l, mid)
        cnt += count(mid, r)
        cnt += r - l
    return cnt

cnt = count(0, int(input()))
arr = list(map(int, input().split()))
arr.sort()
print(*arr)
print(cnt)
