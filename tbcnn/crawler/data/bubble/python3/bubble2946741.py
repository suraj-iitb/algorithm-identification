times = int(input())
numbers = list(map(int, input().split()))
count = 0

for i in range(times - 1, 0, -1):
    for j in range(i):
        if numbers[j] > numbers[j + 1]:
            numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
            count += 1

print(' '.join(map(str, numbers)))
print(count)

