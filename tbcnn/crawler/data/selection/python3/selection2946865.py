times = int(input())
numbers = list(map(int, input().split()))
count = 0
minj = 0

for i in range(times):
    minj = i
    for j in range(i, times, 1):
        if numbers[j] < numbers[minj]:
            minj = j

    if i != minj:
        numbers[i], numbers[minj] = numbers[minj], numbers[i]
        count += 1

print(' '.join(map(str, numbers)))
print(count)

