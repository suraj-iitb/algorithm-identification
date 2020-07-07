n = int(input())
ary = list(map(int,input().split()))

flag = True
cnt=0

for j in range(n):
  flag = True
  while flag:
    flag = False
    i = n #5
    #print(ary) #5 3 2 4 1
    while i > 1:
      i -= 1
      if(ary[i-1] > ary[i]):
        ary[i], ary[i-1] = ary[i-1], ary[i]
        cnt += 1
print(' '.join(map(str,ary)))
print(cnt)

