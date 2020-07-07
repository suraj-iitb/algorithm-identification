
def buble_sort(N,a_count):
  flag = 1
  while(flag):
    flag = 0
    for i in range(1,len(N)):
      if N[i] < N[i-1]:
        tmp = N[i-1]
        N[i-1] = N[i]
        N[i] = tmp
        flag = 1
        a_count += 1
  return a_count


x = 0
N = int(input())
a = list(map(int,input().split()))
w = buble_sort(a,x) 

for  i in range(len(a)):
  if i == len(a)- 1:
    print(a[i],end = "")
  else:
    print(a[i],end = " ")
  
print()
print(w)

