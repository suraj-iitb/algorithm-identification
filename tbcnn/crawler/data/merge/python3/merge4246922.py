MAX = 5 * 10**5
SENTINEL = 2 * 10**9
cnt = 0

def merge(A, left, mid, right):
    n1 = mid - left;
    n2 = right - mid;
    L = A[left:left+n1]
    R = A[mid:mid+n2]

    global cnt

    L.append(SENTINEL)
    R.append(SENTINEL)
    i = 0
    j = 0

    for k in range(left, right):
        cnt += 1
        if L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j+= 1

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2;
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
s = list(map(int, input().split()))
mergeSort(s, 0, len(s))

ans = []
for item in s:
    ans.append(str(item))
print(' '.join(ans))
print(cnt)
