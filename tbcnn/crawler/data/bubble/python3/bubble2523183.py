n = int(input())
a = list(map(int, input().split()))

count = 0
first = 0

while first < n:
    for i in range( n-1, first, -1 ):
        if a[i] < a[i-1]:
            t = a[i]
            a[i] = a[i-1]
            a[i-1] = t
            count += 1
    first += 1

print(*a)
print(count)
