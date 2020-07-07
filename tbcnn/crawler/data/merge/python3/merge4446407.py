def merge(A, left, mid, right):
    global c
    n1 = mid - left
    n2 = right - mid
    L = [0 for e in range(n1+1)]
    R = [0 for e in range(n2+1)]
    L = A[left:mid] + [10 ** 9]
    R = A[mid:right] + [10 ** 9]
    i = 0
    j = 0
    for k in range(left,right):
        if L[i] <= R[j]:
          A[k] = L[i]
          i = i + 1
        else:
          A[k] = R[j]
          j = j + 1
    c += right - left

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

if __name__ == "__main__":
    n = int(input())
    S = [int(e) for e in input().split()]
    c = 0
    mergeSort(S,0,n)
    print(*S)
    print(c)
