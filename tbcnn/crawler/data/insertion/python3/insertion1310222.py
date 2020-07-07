def insertionSort(array, amount):
    for i in range(1, amount):
        v = array[i]
        j = i - 1
        while j >= 0 and array[j] > v:
            array[j + 1] = array[j]
            j = j - 1

        array[j + 1] = v

        for i in range(amount - 1):
            print(array[i], end=" ")
        print(array[amount - 1])

amount = int(input())
array = [0 for i in range(amount)]
array = list(map(int, input().split()))

for i in range(amount - 1):
    print(array[i], end=" ")
print(array[amount - 1])

insertionSort(array, amount)
