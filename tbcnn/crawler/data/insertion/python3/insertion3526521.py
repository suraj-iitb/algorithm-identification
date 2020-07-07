n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    j = i
    while j >= 1 and a[j-1] > a[j]:
        a[j-1], a[j] = a[j], a[j-1]
        j -= 1
    print(*a)
