n = int(input())
a = list(map(int,input().split()))
print(' '.join(map(str,a)))
for i in range(n-1):
    cur = sorted(a[:i+2])
    if i != n-2:
        print(' '.join(map(str,cur))+' '+' '.join(map(str,a[i+2:])))
    else:
        print(' '.join(map(str,cur)))
