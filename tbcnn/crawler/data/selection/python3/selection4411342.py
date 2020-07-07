def selection_sort(lst, n):
    count = 0
    for i in range(n - 1):
        minj = i
        for j in range(n - i):
            if lst[minj] > lst[j + i]:
                minj = j + i
        if minj != i:        
            tmp = lst[i]
            lst[i] = lst[minj]
            lst[minj] = tmp
            count += 1
    map_lst = map(str,lst)
    print(" ".join(map_lst))
    print(count)

n = int(input())
num_list = list(map(int, input().split()))

selection_sort(num_list, n)
