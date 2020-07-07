n=int(input())
s=list(map(int,input().split()))
S=map(str,s)
print(' '.join(S))
for i in range(1,n):
  tmp=s[i]
  j=i-1
  while j>=0 and tmp < s[j]:
    s[j+1]=s[j]
    j -= 1
  s[j+1]=tmp
  S=map(str,s)
  print(' '.join(S))
