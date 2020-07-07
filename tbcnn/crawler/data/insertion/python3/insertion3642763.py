N = int(input())
A = list(map(int, input().split()))


def show(arr):
    for k in range(len(arr)):
        if k != len(arr) - 1:
            print(arr[k], end=' ')
        else:
            print(arr[k])


# 挿入ソート
for i in range(len(A)):
    v = A[i]
    j = i - 1

    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j = j - 1

    A[j+1] = v

    show(A)

