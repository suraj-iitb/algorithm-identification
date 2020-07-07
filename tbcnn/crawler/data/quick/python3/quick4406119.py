def partition(A, l, r):
    i = l - 1
    for j in range(l, r):
        if int(A[j][1]) <= int(A[r][1]):
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

def quick_sort(A, l, r):
    if l < r:
        q = partition(A, l, r)
        quick_sort(A, l, q - 1)
        quick_sort(A, q + 1, r)

n = int(input())
arr = [input().split() + [i] for i in range(n)]
quick_sort(arr, 0, n - 1)
tag = True
for i in range(1, n):
    if arr[i][1] == arr[i - 1][1] and arr[i - 1][2] > arr[i][2]:
        tag = False
        break
print(['Not stable', 'Stable'][tag])
for s in arr:
    print(*s[:2])
