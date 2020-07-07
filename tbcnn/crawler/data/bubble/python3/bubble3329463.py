def showSeq(seq):
  for i in range(len(seq)):
    if i<len(seq)-1: # 最后一个元素的下标为 len(seq)-1
      print(seq[i],end=' ')
    else:
      print(seq[i])
      
      
n = input()
list1 = list(map(int,input().split()))
count = 0

for i in range(len(list1)-1):
  for j in range(len(list1)-1,i,-1):
    if list1[j]<list1[j-1]:
      list1[j],list1[j-1] = list1[j-1],list1[j] 
      # python中的变量保存的是变量值所在的地址； 例如 a=5;b=5 a和b指向内存中同一个地址 id(a) == id(b)
      count+=1
showSeq(list1)
print(count)

