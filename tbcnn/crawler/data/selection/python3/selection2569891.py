n = int(input())
a = list(map(int,input().split()))

mini = 0
count = 0

for i in range(n):
    mini = i
    for j in range(i,n):
        if a[j] < a[mini]:
            mini = j
    a[i],a[mini] = a[mini],a[i]
    if mini != i:
        count += 1

for i in range(n):
    if i != n-1:
        print(a[i],end=" ")
    else:
        print(a[i])
print(count)
