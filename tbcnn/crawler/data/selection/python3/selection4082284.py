n = int(input())
arr = [x for x in list(map(int, input().split()))]

count = 0
for i in range(len(arr)):
  mini = i
  for j in range(i, len(arr)):
    if arr[j] < arr[mini]:
      mini = j
  if mini != i:
    arr[mini], arr[i] = arr[i], arr[mini]
    count += 1

print (" ".join([str(x) for x in arr]))
print (count)
