N = int(input())
l = input().split()
l = [int(s) for s in l]
count = 0
for j in range(N):
    for i in range(N-1):
        if( l[i] > l[i+1]):
            l[i], l[i+1] = l[i+1], l[i]
            count += 1
for i in range(0,len(l)-1):
    print(l[i],end=' ')
print(l[N-1])
print(count)

