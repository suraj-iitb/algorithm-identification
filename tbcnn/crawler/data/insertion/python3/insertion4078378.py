def insert_sort(A):
    a = list(A)
    print(' '.join(map(str, a)))
    for move_index in range(1, len(a)):
        compare_index = move_index -1
        while compare_index >= 0 and a[compare_index] > a[move_index]:
            a[compare_index], a[move_index] = int(a[move_index]), int(a[compare_index])
            compare_index -= 1
            move_index -= 1
        print(' '.join(map(str, a)))
    return a

input()
A = list(map(int, input().split()))
insert_sort(A)
