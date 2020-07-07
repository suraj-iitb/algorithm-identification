N = int(input())
working_list = list(map(int, input().split()))
exchange_count = 0  # 交換回数、つまり、列の乱れの程度を示す反転数あるいは転倒数を記録する。
i = 0
flag = True
while flag:
    flag = False
    for j in range(N-1, i, -1):
        if working_list[j] < working_list[j-1]:
            working_list[j-1], working_list[j] = working_list[j], working_list[j-1]
            flag = True
            exchange_count += 1
    i += 1

print(*working_list)
print(exchange_count)

