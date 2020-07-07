n = int(input())
num_list = input().split()
 
def bubbleSort(num_list, n):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in range(n-1, 0, -1):
            if int(num_list[j]) < int(num_list[j-1]):
                num_list[j], num_list[j-1] = num_list[j-1], num_list[j]
                flag = 1
                count += 1
 
    result = ' '.join(num_list)
    print(result)
    print(count)
 
bubbleSort(num_list, n)
