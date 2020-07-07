import copy
n = int(input())
l = list(map(int, input().split()))
s = copy.deepcopy(l)
m = 1
print(*s)
for i in range(1,n):
    count = 0
    for j in range(0,m):
        if s[i] < l[j]:
            l.insert(j, l[i])
            l.pop(i+1)
            m+=1
            count += 1
            break
    if count == 0:
        l.insert(m, l[i])
        l.pop(i+1)
        m+=1

    print(*l)
