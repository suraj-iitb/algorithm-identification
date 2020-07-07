def print_list(r):
    for i in range(len(r)):
        if i != len(r)-1:
            print (r[i], end=' ')
        else:
            print(r[i])


n=int(input())
r=list(map(int,input().split()))
count_num = 0
for i in range(0, n):
    minj = i
    for j in range(i, n):
        if r[j] < r[minj]:
            minj = j
    v = r[minj]
    r[minj] = r[i]
    r[i] = v
    if minj != i:
        count_num += 1
print_list(r)
print(count_num)
