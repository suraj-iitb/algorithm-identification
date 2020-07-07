n = int(input())
a = [int(x) for x in input().split()]
count = 0

for i in range(n):
    for j in range(0, n-i-1):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
            count += 1

print(' '.join([str(x) for x in a]))
print(count)
