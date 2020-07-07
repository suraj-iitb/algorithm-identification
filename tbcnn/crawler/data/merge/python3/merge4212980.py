def merge(A, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]
    L.append(10**9+1)
    R.append(10**9+1)
    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return right-left


def merge_sort(A, left, right):
    if left+1 < right:
        mid = (left+right)//2
        ans1 = merge_sort(A, left, mid)
        ans2 = merge_sort(A, mid, right)
        return merge(A, left, mid, right)+ans1+ans2
    return 0


N = int(input())
S = list(map(int, input().split()))
ans = merge_sort(S, 0, N)
print(*S)
print(ans)

