# incert sort
N = int(input())
list_num = list(map(int, input().split(" ")))
print(" ".join(map(str, list_num)))

for i_incert in range(1, N):
    num_incert = list_num[i_incert]
    i_cmpr = i_incert - 1
    
    while i_cmpr >= 0 and list_num[i_cmpr] > num_incert:
        list_num[i_cmpr + 1] = list_num[i_cmpr]  # 一つ右にcopy(元のはnum_incertとして保持済)
        i_cmpr -= 1
    list_num[i_cmpr + 1] = num_incert
    print(" ".join(map(str, list_num)))
