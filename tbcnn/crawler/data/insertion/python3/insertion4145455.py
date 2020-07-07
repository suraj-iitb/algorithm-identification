
n = int(input())
numbers = input().split()

numbers = [int(num) for num in numbers]

def show(numbers):
    for i in range(len(numbers)):
        if i != len(numbers) - 1:
            print(numbers[i], end=" ")
        else:
            print(numbers[i])

for i in range(1, n):
    show(numbers)
    key = numbers[i]
    j = i - 1
    while j >= 0 and numbers[j] > key:
        numbers[j+1] = numbers[j]
        j -= 1

    numbers[j+1] = key
show(numbers)

