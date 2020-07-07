N = int(input())
A = list(map(int, input().split()))


def selection_sort(Ary):
    N = len(Ary)
    count = 0
    for i in range(N-1):
        min_j = i
        flag = 0
        for j in range(N-i):
            if Ary[j+i] < Ary[min_j]:
                min_j = j+i
                flag = 1
        Ary[i], Ary[min_j] = Ary[min_j], Ary[i]
        if flag == 1:
            count += 1
            flag = 0
    return Ary, count

A_sorted , count = selection_sort(A)
print(' '.join(map(str, A_sorted)))
print(count)

