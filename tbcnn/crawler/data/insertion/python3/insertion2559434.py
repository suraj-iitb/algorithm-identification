def inputInline():
    N = int(input())
    numbers = list(map(int, input().split(" ")))
    return numbers


def insertionSort(numbers):
    N = len(numbers)
    for i in range(1, N):
        print(" ".join(list(map(str, numbers))))
        j = i - 1
        temp = numbers[i]
        while True:
            if j == -1:
                numbers[0] = temp
                break
            if temp < numbers[j]:
                numbers[j + 1] = numbers[j]
                j -= 1
            else:
                numbers[j + 1] = temp
                break
    return " ".join(list(map(str, numbers)))


print(insertionSort(inputInline()))
