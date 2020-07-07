n=int(input())
nums=list(map(int,input().split()))

def counting_sort(nums,n):
    max_nums=max(nums)
    basket=[0 for i in range(max_nums+1)]
    for i in range(n):
        key=nums[i]
        basket[key]+=1

    answer=[]
    for i in range(len(basket)):
        if basket[i]!=0:
            for j in range(basket[i]):
                answer.append(i)
    return answer

answer=counting_sort(nums,n)
print(' '.join(map(str,answer)))

