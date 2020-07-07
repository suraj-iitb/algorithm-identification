def merge(A, left, mid, right):
    L = A[left:mid] + [int(1e9)]
    R = A[mid:right] + [int(1e9)]
    i,j = 0,0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    global count
    count += (right - left)

def merge_sort(A, left, right):
    if left+1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)


if __name__=='__main__':
    n = int(input())
    A = list(map(int, input().strip().split()))
    count = 0
    merge_sort(A, 0, n)
    print(" ".join(map(str, A)))
    print(count)
