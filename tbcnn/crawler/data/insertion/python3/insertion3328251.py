def show(list1):
  for i in range(len(list1)):
    if i<len(list1)-1:
      print(list1[i],end=' ')
    else:
      print(list1[i])  # print() 默认以回车作为输入结束符

n = int(input()) # input()从标准输入读入一行文本
  
list1 = list(map(int,input().split()))  # str.split() 切割字符串返回list类型
  # map(f,list) 将函数f作用用list的每个元素，返回map类型，用list() 强制类型转换成list类型        

show(list1)

for i in range(1,n):
  key = list1[i]
  j = i-1
  while j>=0 and key<list1[j]:
    list1[j+1]=list1[j]
    j-=1
  list1[j+1] = key
  
  for i in range(n):
    if i<n-1:
      print(list1[i],end=' ')
    else:
      print(list1[i])
