N = int(input())
a = list(map(int, input().strip().split()))
rel = 0
counter = 0
for i in range(0, N):
    minj = i
    for j in range(i+1,N):
        if(a[j]<a[minj]):
            minj = j
            rel += 1
    a[i],a[minj]=a[minj],a[i]
    if(rel>0):
      counter += 1
    rel = 0
print(*a)
print(counter)
