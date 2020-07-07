def counting_sort(lst,ans,max):
    cnt_lst = [0] * (max+1)
    for i in range(0,len(lst)):
        cnt_lst[lst[i]] += 1
    for j in range(1,max+1):
        cnt_lst[j] = cnt_lst[j] + cnt_lst[j-1]

    for k in range(len(lst)-1,-1,-1):
        ans[cnt_lst[lst[k]]-1] = lst[k]
        cnt_lst[lst[k]] -= 1
    return ans

n = int(input())
n_lst = list(map(int,input().split()))
ans = [0] * len(n_lst)
ans = map(str,counting_sort(n_lst,ans,max(n_lst)))
print(' '.join(ans))

