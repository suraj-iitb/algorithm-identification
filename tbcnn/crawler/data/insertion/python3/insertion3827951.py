N=int(input())
nums=list(map(int,input().split()))

for i in range(0,N):
  key = nums[i]
  j= i-1
  while j >= 0 and nums[j] > key:
    nums[j+1] = nums[j]
    j = j-1
  nums[j+1] = key
  print(" ".join(map(str,nums)))
