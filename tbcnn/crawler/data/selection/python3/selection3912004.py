#選択ソート
def print_output(_list):
    for index in range(len(_list)):
        if index == len(_list) - 1:
            print(_list[index])
        else:
            print(_list[index],end=' ')

target_length = int(input())
target_list = list(map(int,input().split()))
choice_count = 0
for i in range(0, target_length - 1):
    minj = i
    for j in range(i, len(target_list)):
        if target_list[j] < target_list[minj]:
            minj = j
    if i != minj:
        choice_count += 1
    tmp = target_list[i]
    target_list[i] = target_list[minj]
    target_list[minj] = tmp
print_output(target_list)
print(choice_count)
