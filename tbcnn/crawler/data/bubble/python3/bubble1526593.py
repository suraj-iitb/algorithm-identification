n = int(input())

numbers = list(map(int, input().split(" ")))

cnt = 0

for i in range(n):
    for j in range(n - 1, i, -1):
        if numbers[j] < numbers[j - 1]:
            tmp = numbers[j]
            numbers[j] = numbers[j - 1]
            numbers[j - 1] = tmp
            cnt += 1

numbers = map(str, numbers)
print(" ".join(numbers))

print(cnt)
