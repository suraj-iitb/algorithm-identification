#初期data
input_number = int(input())
input_list = list(map(int, input().split()))
exchange_count = 0

#アルゴリズム
for i in range(input_number):
    for j in range(input_number-1, i, -1):
        if input_list[j] < input_list[j-1]:
            input_list[j], input_list[j-1] = input_list[j-1], input_list[j]
            exchange_count += 1
    
#処理の実行
print(" ".join(map(str, input_list)))
print(exchange_count)

