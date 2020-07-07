n = int(input())
lis = list(map(int, input().split()))
cont = 0
for i in range(n):
  for j in reversed(range(i+1, n)):
    if lis[j-1] > lis[j]:
      lis[j-1], lis[j] = lis[j], lis[j-1]
      cont += 1
      
print(" ".join(map(str, lis)))
print(cont)
