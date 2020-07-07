m=int(input())
n=list(map(int,input().split()))
cnt=0
for i in range(m-1):
  minj=i
  irekae=0
  for j in range(i+1,m):
    if n[j]<n[minj]:
      minj=j
      irekae=1
  if irekae:
    n[i],n[minj]=n[minj],n[i]
    cnt+=1

print(' '.join(map(str, n)))
print(cnt)
