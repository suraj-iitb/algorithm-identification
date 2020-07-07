n = int(input())

data = input().split()

array = []

for i in data:
  array.append(int(i))

for i in range(1, n):
  print(*array)

  key = array[i]

  j = i - 1

  while j >= 0 and array[j] > key:
    array[j+1] = array[j]
    j -= 1

  array[j+1] = key 

print(*array)

  
