n = int(input())
a = list(map(int, input().split()))

flag = 1 
trade = 0
while flag:
    flag = 0
    for j in range(1, n):
        if a[j-1] > a[j]:
            a[j], a[j-1] = a[j-1], a[j]
            flag = 1
            trade += 1
print(' '.join(list(map(str, a))))
print(trade)
