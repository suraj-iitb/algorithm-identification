
def merge(A, n, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]

    L.append(2000000000)  # これをしないとマージするとき、最後の１回でリスト外アクセスでエラー。
    R.append(2000000000)

    global count
    i, j = 0, 0

    # print('left, mid, right')
    # print(left, mid, right)

    for k in range(left, right, 1):
        count += 1
        # print('i, j, k')
        # print(i, j, k)

        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

        # print('loop end')


def merge_sort(A, n, left, right):
    if right - left > 1:
        mid = (left + right) // 2
        merge_sort(A, n, left, mid)
        merge_sort(A, n, mid, right)
        merge(A, n, left, mid, right)


N = int(input())
A = list(map(int, input().split()))
count = 0

merge_sort(A, N, 0, N)

print(' '.join(map(str, A)))
print(count)

