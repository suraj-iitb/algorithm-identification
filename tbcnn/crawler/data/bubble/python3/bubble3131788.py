n =  int(input())
a = 0

if n <= 0 or 1000 <= n:
  exit()
list1 = list(map(int, input().split()))
#i = 0の時はエラーが出る
for i in range(n-1, 0, -1):
  j = i
  while (j < n) and (list1[j] < list1[j-1]):
    tmp = list1[j-1]
    list1[j-1] =  list1[j]
    list1[j] = tmp
    j += 1
    a += 1
print(' '.join(map(str, list1)))
print(a)

