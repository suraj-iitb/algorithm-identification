INF = float('inf')

cnt = 0

def merge_sort(num_list,left,right):
    if left+1 < right:
        middle = (left+right)//2
        merge_sort(num_list,left,middle)
        merge_sort(num_list,middle,right)
        merge(num_list,left,middle,right)

def merge(num_list,left,middle,right):
    global cnt
    left_list  =  num_list[left:middle] + [INF]
    right_list = num_list[middle:right] + [INF]

    i,j = 0,0
    for k in range(left,right):
        if left_list[i] <= right_list[j]:
            num_list[k]  = left_list[i] 
            i += 1
        else:
            num_list[k]  = right_list[j] 
            j += 1 
        cnt += 1

n = int(input())
n_list = list(map(int,input().split()))
merge_sort(n_list,0,len(n_list))
print(' '.join([str(i) for i in n_list]))
print(cnt)
