N = int(input())
a = [int(i) for i in input().split() ]
for j in range(len(a)):
  if j == len(a) -1:
    print(a[j],end = "")
  else:
    print(a[j],end = " ")    
print()
for i in range(1,len(a)):
  tmp = a[i]
  j = i- 1
  while j >= 0 and a[j] > tmp:
    a[j+1] = a[j]
    j -= 1
  a[j+1] = tmp
  for j in range(len(a)):
      if  j == len(a)-1 :
        print(a[j],end = "")
      else:
        print(a[j],end = " ")
  print()
