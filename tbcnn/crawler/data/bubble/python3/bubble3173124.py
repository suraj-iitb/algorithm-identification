def print_list(r):
    for i in range(len(r)):
        if i != len(r)-1:
            print (r[i], end=' ')
        else:
            print(r[i])

n=int(input())
r=list(map(int,input().split()))
flag = 1
change_num = 0
while flag:
    flag = 0
    for j in range(n-1, 0, -1):
        if r[j] < r[j-1]:
            v = r[j]
            r[j] = r[j-1]
            r[j-1] = v
            flag = 1
            change_num += 1
print_list(r)
print(change_num)
