INF = 10 ** 10

def merge(A, left, mid, right):
    c = 0
    n1 = mid - left
    n2 = right - mid
    Left = [A[left+i] for i in range(n1)]
    Right = [A[mid+i] for i in range(n2)]
    Left.append(INF)
    Right.append(INF)
    i=0
    j=0
    for k in range(left, right):
        c += 1
        if Left[i] <= Right[j]:
            A[k] = Left[i]
            i += 1
        else:
            A[k] = Right[j]
            j += 1
    return c

def mergeSort(hoge, left, right):
    c = 0
    if left+1 < right:
        mid = (left + right) // 2
        c += mergeSort(hoge, left, mid)
        c += mergeSort(hoge, mid, right)
        c += merge(hoge, left, mid, right)
    return c

if __name__ == '__main__':
    _ = input()
    hoge = [int(x) for x in input().split()]
    c = mergeSort(hoge, 0, len(hoge))
    print (' '.join([str(x) for x in hoge]))
    print (c)
