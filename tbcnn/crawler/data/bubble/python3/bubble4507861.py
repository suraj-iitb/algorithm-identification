size = int(input())
l = []

for i in map(int, input().split()):
    l.append(i)

sort_cnt = 0
reversed_cnt = 0

for j in range(size - 1,0,-1):
    for i in range(size - 1,sort_cnt,-1):
        tmp = l[i-1]
        if l[i] < l[i-1]:
            l[i-1] = l[i]
            l[i] = tmp
            reversed_cnt += 1
    sort_cnt += 1

print(' '.join(map(str,l)))
print(reversed_cnt)
