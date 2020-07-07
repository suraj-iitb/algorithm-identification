N = int(input())
l = input().split()
l = [int(s) for s in l]
count = 0
for j in range(N-1):
    min = l[j]
    for i in range(j,N):
        if( min > l[i]):
            min = l[i]
            a = i
    if(l[j]>min):
        l[j],l[a] = l[a],l[j]
        count += 1
for i in range(0,len(l)-1):
    print(l[i],end=' ')
print(l[N-1])
print(count)
