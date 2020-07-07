def printData(data) :
    for i, value in enumerate(data) :
        if i > 0 :
            print(" ", end = "")
        print(value, end = "")
    print()
    
def insertionSort(data, N) :
    for i in range(1, N) :
        target = data[i]
        j = i -1
        while j >= 0 and target < data[j] :
            data[j + 1] = data[j]
            j -= 1
        data[j + 1] = target
        printData(data)
        
N = int(input())
data = [int(char) for char in input().split()]
printData(data)
insertionSort(data, N)
            
