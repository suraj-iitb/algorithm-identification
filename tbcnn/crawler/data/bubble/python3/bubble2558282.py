def inputInline():
    N=int(input())
    numbers=list(map(int,input().split(" ")))
    return numbers
def bubbleSort(list):
    N=len(list)
    count=0
    flag=True
    while flag:
        flag=False
        for i in range(N-1):
            if list[i]>list[i+1]:
                temp=list[i]
                list[i]=list[i+1]
                list[i+1]=temp
                flag=True
                count+=1
    return (list,count)
result=bubbleSort(inputInline())
print(" ".join(list(map(str,result[0]))))
print(result[1])
