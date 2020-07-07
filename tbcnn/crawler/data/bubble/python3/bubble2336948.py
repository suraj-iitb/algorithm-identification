itemCount = int(input())
items = list(map(int, input().split(" ")))

def bubbleSort(items, itemCount):
    hasPrevious = True
    swapCount = 0
    while hasPrevious:
        hasPrevious = False
        for index in reversed(range(1, itemCount )):
            if items[index] < items[index - 1]:
                items[index], items[index - 1] = [items[index - 1], items[index]]
                hasPrevious = True
                swapCount += 1
    print(" ".join(map(str, items)))
    print(swapCount)

bubbleSort(items, itemCount)
