def insetSort(lst,n):
    count = 0
    for i in range(0,n):
        min = i
        for j in range(i,n):
            if lst[j] < lst[min]: min = j
        if lst[i] != lst[min]: count += 1
        lst[i],lst[min] = lst[min],lst[i]

    return lst,count

n = int(input())
lst = [int(i) for i in input().split()]
lst = insetSort(lst,n)

print(*lst[0])
print(lst[1])
