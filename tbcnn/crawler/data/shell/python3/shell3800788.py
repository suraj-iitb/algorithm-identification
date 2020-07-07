def insertionsort(values, g):
  global exchange_count
  # for j in range(g, valuenum):
  #   i = j - g
  #   while i >= 0 and values[i] > values[j]:
  #     values[i], values[j] = values[j], values[i]
  #     exchange_count += 1
  #     i -= g
  #     j -= g
  for i in range(g, valuenum):
    v = values[i]
    j = i - g
    while j >= 0 and values[j] > v:
      values[j+g] = values[j]
      j = j - g
      exchange_count += 1
    values[j+g] = v

valuenum = int(input())
values = [int(input()) for _ in range(valuenum)]

# gs = [1]
# g = 4
# while g < valuenum:
#   gs.append(g)
#   g = 3 * g + 1
# gs.reverse()
gs = [int((2.25**i-1)/1.25)for i in range(17,0,-1)]
gs = [v for v in gs if v <= valuenum]

print(len(gs))
print(' '.join(map(lambda g:str(g), gs)).strip())

exchange_count = 0

for g in gs:
  insertionsort(values, g)

print(exchange_count)
for value in values:
  print(value)
