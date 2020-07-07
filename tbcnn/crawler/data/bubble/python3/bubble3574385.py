#ALDS1_2_A
n = int(input())
a = [int(i) for i in input().split()]
cnt = 0
for ni in range(n):
  for ii in range(n-1,ni,-1):
    if a[ii] < a[ii-1]:
      a[ii], a[ii-1] = a[ii-1], a[ii]
      cnt += 1
print(" ".join([str(i) for i in a]))
print(cnt)
