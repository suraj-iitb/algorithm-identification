n = int(input())
a = list(map(int,input().split()))
flag = 1
cnt = 0
while flag:
  flag = 0
  for i in range(len(a)):
    if i > 0 and a[i] < a[i-1]:
      a[i],a[i-1] = a[i-1],a[i]
      flag = 1
      cnt += 1
print(" ".join((str(i) for i in a)))
print(cnt)
