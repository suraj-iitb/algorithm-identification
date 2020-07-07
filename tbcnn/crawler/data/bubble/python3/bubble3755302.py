N=int(input())
A=list(map(int, input().split()))
cnt=0
flg=1
while flg:
  flg=0
  for i in range(1,N)[::-1]:
    if A[i] < A[i-1]:
      _=A[i]
      A[i]=A[i-1]
      A[i-1]=_
      flg=1
      cnt+=1
print(*A)
print(cnt)
