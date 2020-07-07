N = int(input())
a = list(map(int, input().strip().split()))

for j in range (1,N):
    for i in range(0, N-1):
        print(a[i], end=" ")
    print(a[N-1])
    temp = a[j]
    for k in range(0,j):
        if(temp<a[k]):
          a.pop(j)
          a.insert(k,temp)
          break
for l in range(0, N-1):
  print(a[l], end=" ")
print(a[N-1])
