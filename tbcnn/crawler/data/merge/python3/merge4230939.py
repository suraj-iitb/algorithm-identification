N = int(input())
num_list = [int(item) for item in input().split()]


def merge(A, left, mid, right):

    L = A[left : mid] + [100**5]
    R = A[mid: right] + [100**5]
 
    cnt = 0
    i, j = 0, 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        # print(A, left, mid, right)
    return cnt


def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right)//2
        cnt_L = mergeSort(A, left, mid)
        cnt_R = mergeSort(A, mid, right)
        return merge(A, left, mid, right) + cnt_L + cnt_R
    return 0


res_cnt = mergeSort(num_list, 0, N)
print(*num_list)
print(res_cnt)
