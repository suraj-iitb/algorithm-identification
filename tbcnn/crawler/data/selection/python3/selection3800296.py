valuenum = int(input())
values = [int(value) for value in input().strip().split()]

exchange_count = 0

for i in range(valuenum):
  min_num = i
  for j in range(i + 1, valuenum):
    if values[j] < values[min_num]:
      min_num = j
  if values[i] > values[min_num]:
    values[i], values[min_num] = values[min_num], values[i]
    exchange_count += 1

ans = map(lambda value:str(value), values)

print(' '.join(ans).strip())
print(str(exchange_count))
