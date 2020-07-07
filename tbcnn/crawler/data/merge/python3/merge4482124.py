num = int(input())
s = list(map(int, input().split()))
cnt = 0

def merge(A, left, mid, right):
    global cnt
    
    L = A[left:mid] + [10**9 + 1]
    R = A[mid:right] + [10**9 + 1]
    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    cnt += right - left

def merge_sort(A, left, right):
    if (left + 1) < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)


merge_sort(s, 0, num)

print(*s)
print(cnt)
