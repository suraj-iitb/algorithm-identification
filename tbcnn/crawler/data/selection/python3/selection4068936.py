n = int(input())
a = list(map(int, input().split()))
count = 0

for i in range(0, n):
    minj = i
    for j in range(i+1, n):
        if a[j] < a[minj]:
            minj = j
    if i != minj:
        x = a[i]
        a[i] = a[minj]
        a[minj] = x
        count = count + 1

print(*a)
print(count)
