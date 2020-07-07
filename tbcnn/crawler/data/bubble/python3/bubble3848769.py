m=int(input())
n=list(map(int,input().split()))
cnt=0
flag=1
while flag:
  flag=0
  for j in range(m-1,0,-1):
    if n[j]<n[j-1]:
      n[j],n[j-1]=n[j-1],n[j]
      cnt+=1
      flag=1

print(' '.join(map(str, n)))
print(cnt)
