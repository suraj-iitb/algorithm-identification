def bubbleSort():
    N = int(input())
    lst = list(map(int, input().split()))
    
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(1, N)[::-1]:
            if lst[i-1] > lst[i]:
                lst[i], lst[i-1] = lst[i-1], lst[i]
                count += 1
                flag = 1
    print(*lst)
    print(count)

bubbleSort()
