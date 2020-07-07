n = int(input())
l = []
l = input().split()
l = list(map(int,l))
print(*l)
for i in range(1,n):
    v = l[i]
    j = i - 1
    while j >= 0 and l[j] > v:
        l[j+1] = l[j]
        j = j - 1
    l[j+1] = v
    print(*l)
