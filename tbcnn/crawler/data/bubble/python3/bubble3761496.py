count = int(input())
numbers = input().split(" ")
for i in range(len(numbers)):
    numbers[i] = int(numbers[i])


if __name__ == "__main__":
    swap_count = 0

    flag = True
    while flag:
        flag = False
        for j in range(count-1, 0, -1):
            if numbers[j] < numbers[j-1]:
                numbers[j], numbers[j-1] = numbers[j-1], numbers[j]
                swap_count += 1
                flag = True

    print(*numbers)
    print(swap_count)

