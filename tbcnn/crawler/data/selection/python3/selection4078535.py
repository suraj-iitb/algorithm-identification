def selection_sort(A):
    a = list(A)
    swap_count = 0

    for i in range(0, len(A)-1):
        i_min = i
        for j in range(i+1, len(A)):
            if a[j] < a[i_min]:
                i_min = j
        if i is not i_min:
            a[i], a[i_min] = a[i_min], a[i]
            swap_count += 1
    
    print(' '.join(map(str, a)))
    print(swap_count)

input()
selection_sort(list(map(int, input().split())))
