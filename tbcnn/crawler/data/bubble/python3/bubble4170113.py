# 5
# 5 3 2 4 1

# j = 0
# 

n = int(input())
arr = [ int(i) for i in input().split(" ")]

ans = 0

for i in range(len(arr) - 1):
  j = len(arr)-1
  for _ in range(len(arr)-i-1):
    if arr[j-1] > arr[j]:
      b = max(arr[j], arr[j-1])
      s = min(arr[j], arr[j-1])
      arr[j] = b
      arr[j-1] = s
      ans += 1
    j = j - 1
    
print(" ".join([str(i) for i in arr]))
print(ans)


