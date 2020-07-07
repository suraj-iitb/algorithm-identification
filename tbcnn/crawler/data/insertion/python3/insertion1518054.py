n = input()
n = int(n)

numbers = input()
numbers = numbers.split(' ')

for i in range(1, n):
    print(" ".join(numbers))
    j = i - 1
    while (j >= 0) and (int(numbers[j]) > int(numbers[j + 1])):
        numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
        j -= 1
print(" ".join(numbers))
