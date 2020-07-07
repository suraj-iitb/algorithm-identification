roop_num = int(input())
values = [int(value) for value in input().split()]

exchange_num = 0

while roop_num:
  for i in range(1,roop_num):
    if values[i - 1] > values[i]:
      values[i - 1], values[i] = values[i], values[i - 1]
      exchange_num += 1
  roop_num -= 1

ans = map(lambda value:str(value), values)

print(' '.join(ans).strip())
print(exchange_num)
