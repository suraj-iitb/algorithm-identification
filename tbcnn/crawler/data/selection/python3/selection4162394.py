#初期data
input_number = int(input())
input_list = list(map(int, input().split()))
exchange_count = 0

#アルゴリズム
for i in range(input_number):
    min_data = input_list[i]
    min_number = -1
    for j in range(i+1, input_number):
        if min_data > input_list[j]:
            min_data = input_list[j]
            min_number = j
    if min_number != -1:
        input_list[i], input_list[min_number] = input_list[min_number], input_list[i]
        exchange_count += 1

#処理の実行
print(" ".join(map(str, input_list)))
print(exchange_count)

