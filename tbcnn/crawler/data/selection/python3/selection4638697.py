def selection_sort(A):
    cnt = 0
    for i in range(0, len(A)):
        min = i
        for j in range(i + 1, len(A)):
            if A[min] > A[j]:
                min = j
        if min != i:
            A[i], A[min] = A[min], A[i]
            cnt += 1
    print(' '.join(map(str, A)))
    print(cnt)


if __name__ == '__main__':
    n = int(input())
    l = list(map(int, input().split()))
    selection_sort(l)

