n = int(input())
a = list(map(int, input().split()))
count = 0
minj = 0
for i in range(n):
    minj = i
    for j in range(i,n):
        if a[j] <a[minj]:
            minj = j
    if i != minj:
        count += 1      
    c = a[i]
    a[i] = a[minj]
    a[minj] = c
    

b = [str(i) for i in a]
print(" ".join(b))
print(count)
