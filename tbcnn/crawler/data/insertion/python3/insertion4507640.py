size = int(input())
l = []
for i in map(int, input().split()):
    l.append(i)
print(' '.join(map(str,l)))

for i in range(1,size):
    tmp = l[i]
    j = i - 1

    while l[j] > tmp and j >= 0:
        l[j + 1] = l[j]
        j = j - 1
    l[j + 1] = tmp
    
    print(' '.join(map(str,l)))
