#coding:utf-8
n = int(input())
numbers = list(map(int, input().split()))
count = 0

for i in range(n-1):
    for j in range(n-1, i, -1):
        if numbers[j] < numbers[j-1]:
            numbers[j], numbers[j-1] = numbers[j-1], numbers[j]
            count += 1

print(*numbers)
print(count)
