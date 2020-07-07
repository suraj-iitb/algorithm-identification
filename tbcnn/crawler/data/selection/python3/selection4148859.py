def printData(data) :
    for i, value in enumerate(data) :
        if i > 0 :
            print(" ", end = "")
        print(value, end = "")
    print()
    
def selectionSort(data, N) :
    count = 0
    for i in range(0, N) :
        sortIdx = i
        for j in range(i + 1, N) :
            if data[sortIdx] > data[j] :
                sortIdx = j
        if sortIdx != i :
            buf = data[sortIdx]
            data[sortIdx] = data[i]
            data[i] = buf
            count += 1
            
    printData(data)
    print(count)
    
N = int(input())
data = [int(char) for char in input().split()]
selectionSort(data, N)
            
        
