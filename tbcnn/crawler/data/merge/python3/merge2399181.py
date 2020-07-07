INF = 10000000000


def merge(A, left, mid, right):
    global num
    leftA = A[left:mid]
    rightA = A[mid:right]
    leftA.append(INF)
    rightA.append(INF)
    l = 0
    r = 0
    for i in range(left, right):
        num += 1
        if leftA[l] <= rightA[r]:
            A[i] = leftA[l]
            l += 1
        else:
            A[i] = rightA[r]
            r += 1


def mergeSort(A, left, right):
    if right - left < 2:
        return
    mid = left + (right - left) // 2
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)


if __name__ == "__main__":
    n = int(input())
    S = list(map(int, input().split()))
    num = 0
    mergeSort(S, 0, len(S))
    print(" ".join(map(str, S)))
    print(num)
