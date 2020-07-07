def insertsort(N_list):
    sort_list = list(N_list)
    ans = [str(i) for i in sort_list]
    print(" ".join(ans))
    for i in range(1,len(N_list)):
        target = sort_list[i]
        j = i-1
        while j >= 0 and sort_list[j] > target:
            sort_list[j], sort_list[j+1] = target, sort_list[j]
            j -= 1
        ans = [str(i) for i in sort_list]
        print(" ".join(ans))
            
    
N = int(input())
N_list = list(map(int,input().split()))
insertsort(N_list)
