n = int(input())
a = list(map(int, input().split()))

def bubbleSort(a, n):
  flag = 1
  count = 0
  while flag:
    flag = 0
    for j in reversed(range(1,n)):
      if a[j] < a[j-1]:
        temp = a[j]
        a[j] = a[j-1]
        a[j-1] = temp
        flag = 1
        count += 1
  return count

count = bubbleSort(a,n)
print(*a)
print(count)
