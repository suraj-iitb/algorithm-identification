N = int(input())
working_list = list(map(int, input().split()))
exchange_count = 0
for i in range(N):
    minj = i
    for j in range(i+1, N):
        if working_list[j] < working_list[minj]:
            minj = j
    if i != minj:
        working_list[i], working_list[minj] = working_list[minj], working_list[i]
        exchange_count += 1

print(*working_list)
print(exchange_count)
