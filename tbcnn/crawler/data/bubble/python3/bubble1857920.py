count = 0
list1 = []

a = int(input())
list1  = list(map(int, input(). split()))

for i in range(len(list1)):
  for n in range(len(list1) - i - 1):
    if(list1[n] > list1[n + 1]):
      tmp = list1[n]
      list1[n] = list1[n + 1]
      list1[n + 1] = tmp
      count += 1

print(" ".join(str(x) for x in list1))
print(count)
