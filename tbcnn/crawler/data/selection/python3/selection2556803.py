n = int(input())
a = list(map(int,input().split()))
count = 0
for i in range(n-1):
    flag = 0
    min_j = i
    for j in range(i,n):
        if a[j] < a[min_j]:
            min_j = j
            flag = 1
    if flag:
        a[i], a[min_j] = a[min_j], a[i]
        count += 1
print(" ".join(map(str,a)))
print(count)
