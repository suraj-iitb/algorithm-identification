class Selection_sort:
    def __init__(self):
        self.swap_num=0
    
    def sort(self,data):
        for i in range(len(data)):
            mini=i
            for j in range(i+1,len(data)):
                if(data[j] < data[mini]):
                    mini=j
            if(mini!=i):
                data[i],data[mini]=data[mini],data[i]
                self.swap_num+=1
        return data






n=int(input())
data=list(map(int,input().split()))
selection_sort=Selection_sort()
print(" ".join(list(map(str,selection_sort.sort(data)))))
print(selection_sort.swap_num)
