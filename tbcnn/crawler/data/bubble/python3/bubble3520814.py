n=int(input())
arr=list(map(int,input().split()))
cnt=0
for i in range(n):
  for j in range(n-1,i,-1):
    if arr[j]<arr[j-1]:
      cnt+=1
      arr[j],arr[j-1]=arr[j-1],arr[j]
print(' '.join(map(str,arr)))
print(cnt)
