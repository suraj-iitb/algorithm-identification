#挿入ソート
def print_output(_list):
    for index in range(len(_list)):
        if index == len(_list) - 1:
            print(_list[index])
        else:
            print(_list[index],end=' ')

target_length = int(input())
target_list = list(map(int,input().split()))
print_output(target_list)
for index in range(1, target_length):
    v = target_list[index]
    j = index -1
    while (j >= 0 and target_list[j] > v):
        target_list[j + 1] = target_list[j]
        j -= 1
    target_list[j + 1] = v
    print_output(target_list)
