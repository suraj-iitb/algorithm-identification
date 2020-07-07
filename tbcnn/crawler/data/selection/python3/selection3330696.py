# 选择排序
def showList(list1):
  for i in range(len(list1)):
    if(i<len(list1)-1):
      print(list1[i],end=' ')
    else:
      print(list1[i])
      
def selectionSort(seq):
  swapCount = 0
  for i in range(len(seq)):
    minIndex = i
    for j in range(i+1,len(seq)):
      if seq[minIndex]>seq[j]:
        minIndex = j
    if i!=minIndex:
      seq[i],seq[minIndex] = seq[minIndex],seq[i]
      swapCount+=1
  return swapCount

n = input()
list1 = list(map(int,input().split()))

count = selectionSort(list1)
showList(list1)
print(count)
