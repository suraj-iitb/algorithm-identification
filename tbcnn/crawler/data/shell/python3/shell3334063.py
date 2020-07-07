
def insertionSort(list1,g):
  cnt=0
  for i in range(g,len(list1)):
    value = list1[i]
    j = i-g
    while j>=0 and list1[j]>value:
      list1[j+g] = list1[j]
      j = j-g
      cnt +=1
    list1[j+g]=value
    
  return cnt
    
def shellSort(list1):
  cnt = 0
  G = []
  n1 = len(list1)
  while int(n1/3)>0:
    n1 = int(n1/3)+1
    G.append(n1)
  G.append(1)
  for i in range(len(G)):
    cnt+=insertionSort(list1,G[i])
  print(len(G))
  print(*G)
  print(cnt)  
    
    
  

n = int(input())
list1 = []
for i in range(n):
  list1.append(int(input()))

shellSort(list1)


for i in range(n):
  print(list1[i])
