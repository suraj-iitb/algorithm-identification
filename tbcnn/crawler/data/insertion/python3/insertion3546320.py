num = int(input())
lis = list(map(int, input().split()))
print(' '.join([str(h) for h in lis]))
for i in range(1, num):
    v = lis[i]
    j = i - 1
    while lis[j] > v and j >= 0:
        lis[j + 1] = lis[j]
        j -= 1
    lis[j+1] = v
    print(' '.join([str(h) for h in lis]))
