def merge(a, l, m, r):
  global count
  Left = a[l:m]
  Left.append(1e10)
  Right = a[m:r]
  Right.append(1e10)
  i, j = 0, 0
  for k in range(l, r):
    count += 1
    if Left[i] <= Right[j]:
      a[k] = Left[i]
      i += 1
    else:
      a[k] = Right[j]
      j += 1

def sort(a, l, r):
  if r-l > 1:
    m = (l+r)//2
    sort(a, l, m)
    sort(a, m, r)
    merge(a, l, m, r)
       
       
count=0
n=int(input())
a=[int(i) for i in input().split()]
sort(a, 0, n)
print(*a)
print(count)
