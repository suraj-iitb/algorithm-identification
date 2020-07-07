n = int(input())
a = list(map(str, input().split()))
a_swap = 0

flag = True
while flag:
    flag = False
    for j in range(n-1,0,-1):
      if int(a[j]) < int(a[j-1]):
       a[j],a[j-1] = a[j-1],a[j]
       flag = True
       a_swap += 1

print(" ".join(a))
print(a_swap)
