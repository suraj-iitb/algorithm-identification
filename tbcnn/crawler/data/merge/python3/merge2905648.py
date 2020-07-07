count = 0

def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    L, R = A[left: left + n1], A[mid: mid + n2]

    L.append(2000000000)
    R.append(2000000000)

    i, j = 0, 0
    for k in range(left, right):
        global count
        count += 1
        #print("k", k, "l", left, "m", mid, "r", right, "L", L, "R", R)
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    #print("l", left, "r", right)
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
input_list = list(map(int, input().split(' ')))

mergeSort(input_list, 0, n)

print(*input_list)
print(count)


