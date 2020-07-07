INFTY = 1000000001

def merge(A, left, mid, right):
    global cnt

    L = A[left:mid]
    R = A[mid:right]

    L.append(INFTY)
    R.append(INFTY)

    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
          A[k] = L[i]
          i += 1
        else:
          A[k] = R[j]
          j += 1

        cnt += 1



def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2

        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)



n = int(input())
S = list(map(int, input().split()))

cnt = 0

merge_sort(S, 0, len(S))


print(*S)
print(cnt)

