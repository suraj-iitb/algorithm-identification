def bubbleSort(lst,n):
    flag = True
    count = 0
    while flag:
        flag = False
        for i in range(n-1,0,-1):
            if lst[i] < lst[i - 1]:
                lst[i],lst[i-1] = lst[i-1],lst[i]
                count += 1
                flag = True
    return lst,count


num = int(input())
lst = [int(i) for i in input().split()]

lst = bubbleSort(lst,num)
print(*lst[0])
print(lst[1])
