def Show():
    print(' '.join([str(aa) for aa in a]))

n = int(input())
a = list(map(int, input().split()))
Show()
for i in range(1, n):
    target = a[i]
    j = i-1 
    while j >= 0 and a[j] > target:
        a[j+1] = a[j] 
        j -= 1
    a[j+1] = target
    Show()
