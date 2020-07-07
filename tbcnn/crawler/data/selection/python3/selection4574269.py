N = int(input())
a = list(int(x) for x in input().split())
count = 0
for i in range(N):
  min_a = i
  for j in range(i,N):
    if a[j] < a[min_a]:
      min_a = j
  if min_a != i:
    count += 1
  tmp = a[i]
  a[i] = a[min_a]
  a[min_a] = tmp

for k in range(N):
  if k == N-1:
    print(a[k],end ="")
  else:
    print(a[k],end =" ")
    
print()
print(count)
