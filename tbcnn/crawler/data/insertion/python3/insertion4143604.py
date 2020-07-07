x = int(input())
l_t = [int(i)for i in input().split()]
print(' '.join([str(p) for p in l_t]))
for i in range(1,x):
    v = l_t[i]
    j = i - 1
    while j >= 0 and l_t[j] > v:
        l_t[j + 1] = l_t[j]
        j = j - 1
    l_t[j + 1] = v
    print(' '.join([str(p) for p in l_t]))
    
