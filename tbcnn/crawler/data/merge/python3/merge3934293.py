SENTINEL = 9999999999999

count = 0

def merge(S, n, left, mid, right):
    global SENTINEL
    global count
    n1 = mid - left
    n2 = right - mid
    L = S[left:mid] + [SENTINEL]
    R = S[mid:right] + [SENTINEL]
    i = j = 0
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            S[k] = L[i]
            i += 1
        else:
            S[k] = R[j]
            j += 1

def mergeSort(S, n, left, right):
    if left + 1 < right:
        mid = int((left + right) / 2)
        mergeSort(S, n, left, mid)
        mergeSort(S, n, mid, right)
        merge(S, n, left, mid, right)

n = int(input())
S = list(map(int, input().split(" ")))

mergeSort(S, n, 0, n)
print(*S)
print(count)
