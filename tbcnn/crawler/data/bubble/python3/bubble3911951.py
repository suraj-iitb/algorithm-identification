#バブルソート
def print_output(_list):
    for index in range(len(_list)):
        if index == len(_list) - 1:
            print(_list[index])
        else:
            print(_list[index],end=' ')

target_length = int(input())
target_list = list(map(int,input().split()))

bubble_count = 0
for index in range(1, target_length):
    for compare_index in reversed(range(index)):
        if target_list[compare_index + 1] < target_list[compare_index]:
            target_list[compare_index + 1] ,target_list[compare_index] = target_list[compare_index] ,target_list[compare_index + 1]
            bubble_count += 1
        else:            
            break
print_output(target_list)
print(bubble_count)
