def bubble_sort(A):
    a = list(A)
    swap_count = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(len(a)-1, 0, -1):
            if a[j-1] > a[j]:
                a[j-1], a[j] = a[j], a[j-1]
                swap_count += 1
                flag = 1
    print(' '.join(map(str, a)))
    print(swap_count)

input()
bubble_sort(list(map(int, input().split())))
