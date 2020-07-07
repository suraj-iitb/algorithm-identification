N = int(input())

num_list = list(map(int,input().split()))

cnt = 0

for i in range(N):
    minj = i
    for j in range(i,N):
        if num_list[j] < num_list[minj]:
            minj = j
    if i != minj:
        num_list[i],num_list[minj] = num_list[minj],num_list[i]
        cnt+=1
        
print(*num_list)
print(cnt)
