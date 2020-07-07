def counting_sort(data):
    count_list=[0]*(max(data)+1)
    sorted_data=[0]*len(data)
    
    for i in data:
        count_list[i]+=1
    
    for loop in range(len(count_list) -1 ):
        count_list[loop+1]+=count_list[loop]
    
    for i in data:
        sorted_data[count_list[i] -1 ] =i
        count_list[i]-=1
    
    return sorted_data


n=int(input())
data=list(map(int,input().split()))
result=counting_sort(data)

print(" ".join(list(map(str,result))))
