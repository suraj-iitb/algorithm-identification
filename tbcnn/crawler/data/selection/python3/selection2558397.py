def selectionSort(numbers):
    n = len(numbers)
    count = 0
    for i in range(n):
        min_j = i
        for j in range(i + 1, n):
            if numbers[j] < numbers[min_j]:
                min_j = j
        if min_j != i:
            temp = numbers[i]
            numbers[i] = numbers[min_j]
            numbers[min_j] = temp
            count += 1
    return (" ".join(list(map(str, numbers))), count)


def inputInline():
    int(input())
    numbers = list(map(int, input().split(" ")))
    return numbers


result = selectionSort(inputInline())
print(result[0])
print(result[1])
