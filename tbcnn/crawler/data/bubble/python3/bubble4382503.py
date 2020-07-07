def bubble_sort(data, n):
    end_of_line = 0
    change_num = 0

    while end_of_line < n-1:
        for i in reversed(range(end_of_line,n)):
            if data[i-1] > data[i]:
                v = data[i]
                data[i] = data[i-1]
                data[i-1] = v
                change_num += 1
                break
            if end_of_line >= i-1:
                end_of_line += 1
                break
    
    return data, change_num


num = int(input())
data = list(map(int, input().split()))

sorted_data, chage_num = bubble_sort(data,num)

print(' '.join(map(str,sorted_data)))
print("%d"%chage_num)

