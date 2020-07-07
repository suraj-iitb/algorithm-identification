num = int(input())
sort_list = list(map(int,input().split()))

cnt = 0
for i in range(num):
    for j in reversed(range(i+1,num)):
        if sort_list[j] < sort_list[j-1]:
            sort_list[j],sort_list[j-1] = sort_list[j-1],sort_list[j]
            cnt += 1

print(" ".join([str(i) for i in sort_list]))
print(cnt)

