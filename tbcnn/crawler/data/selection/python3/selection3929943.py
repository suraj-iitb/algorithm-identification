n = int(input())
a = list(map(int, input().split()))

def selectionSort(a, n):
  count = 0
  for i in range(n):
    minj = i
    for j in range(i,n):
      if a[j] < a[minj]:
        minj = j
    if minj != i:
      count += 1
    a[i],a[minj] = a[minj],a[i]
  return count
  
count = selectionSort(a,n)
print(*a)
print(count)



