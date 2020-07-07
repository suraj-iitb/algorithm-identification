n = int(input())
arr = [x for x in list(map(int, input().split()))]

flag = True
count = 0
while flag:
  flag = False
  for i in reversed(range(1, len(arr))):
    if arr[i] < arr[i - 1]:
      tmp = arr[i]
      arr[i] = arr[i - 1]
      arr[i - 1] = tmp
      flag = True
      count += 1

print(" ".join([str(x) for x in arr]))
print(count)
