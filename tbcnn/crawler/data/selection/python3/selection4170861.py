n = int(input())
arr = [ int(i) for i in input().split(" ")]

cnt = 0
for i in range(len(arr)-1):
  
  minj = i+1
  for j in range(i, len(arr)):
    if arr[j] < arr[minj]:
      minj = j
  
  tmpCur = arr[i]
  tmpMin = arr[minj]
  if tmpCur > tmpMin:
    cnt += 1
    arr[i], arr[minj] = tmpMin, tmpCur

print(" ".join([str(i) for i in arr]))
print(cnt)
