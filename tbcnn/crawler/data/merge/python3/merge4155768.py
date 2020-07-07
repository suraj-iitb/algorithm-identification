# Merge Sort
N = int(input())
lst = list(map(int, input().split()))

INF = 10**9 + 1
cnt = 0
def merge(A, left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid]
    L.append(INF)  # 番兵
    R = A[mid:right]
    R.append(INF)  # 番兵
    i, j = 0, 0
    for k in range(left, right):
        cnt += 1
        if (L[i] <= R[j]):
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
def merge_sort(A, left, right):
    if (right - left > 1):
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)
        
merge_sort(lst, 0, len(lst))
print(*lst)
print(cnt)
