class Bubble_sort:
    def __init__(self):
        self.swap_num=0
    
    def sort(self,n,list):
        for i in range(n):
            for j in range(i+1,n)[::-1]:
                if(list[j] < list[j-1]):
                    list[j],list[j-1]=list[j-1],list[j]
                    self.swap_num+=1
        return list




n=int(input())
data=list(map(int,input().split()))
bubble_sort=Bubble_sort()
print(" ".join(list(map(str,bubble_sort.sort(n,data)))))
print(bubble_sort.swap_num)
