n,*a=map(int,open(0).read().split())
for i in range(1,n+1):a[:i]=sorted(a[:i]);print(*a)
