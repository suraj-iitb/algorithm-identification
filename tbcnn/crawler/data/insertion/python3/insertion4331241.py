def insertion_sort(lst):
    for i in range(1, len(lst)):
        v = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > v:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = v
        print(*lst)

n = int(input())
lst = list(map(int, input().split()))
print(*lst)
insertion_sort(lst)
