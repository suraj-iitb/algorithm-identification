n = int(input())
a = []
a = input().split()
a = list(map(int,a))
num = 0
for i in range(n):
    minj = i
    for j in range(i,n):
        if a[j] < a[minj]:
            minj = j
    if i != minj:
        a[i], a[minj] = a[minj], a[i]
        num = num + 1

print(*a)
print(num)

