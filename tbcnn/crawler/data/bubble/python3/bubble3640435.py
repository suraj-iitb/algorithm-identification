n = int(input())
a = list(map(int,input().split()))
flag = True
counter = 0
while flag:
  flag = False
  for j in range(1,n):
    if a[j] < a[j-1]:
      temp = a[j]
      a[j] = a[j-1]
      a[j-1] = temp
      flag = True
      counter += 1
print(" ".join(map(str,a)))
print(counter)
