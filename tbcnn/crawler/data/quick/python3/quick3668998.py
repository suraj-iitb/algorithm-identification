def partition(arr, p, r):
    x = int(arr[r][1])
    i = p
    for j in range(p, r):
        if int(arr[j][1]) <= x:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i


def quicksort(arr, p, r):
    if p < r:
        q = partition(arr, p, r)
        quicksort(arr, p, q - 1)
        quicksort(arr, q + 1, r)


n = int(input())
arr = [input().split() for _ in range(n)]
arr_s = sorted(arr, key=lambda x:x[1])
quicksort(arr, 0, n - 1)


print("Stable" if arr == arr_s else "Not stable")
for ele in arr:
    print(*ele)


