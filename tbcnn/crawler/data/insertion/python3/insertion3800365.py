valuenum = int(input())

Input = input()
print(Input)
values = [int(value) for value in Input.split()]

for i in range(1,valuenum):
  for j in range(0,i):
    if values[i] < values[j]:
      values.insert(j, values[i])
      values.pop(i + 1)
      break

  ans = map(lambda value:str(value), values)
  print(' '.join(ans).strip())
