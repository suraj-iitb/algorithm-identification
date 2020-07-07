def printData(data) :
    for i, value in enumerate(data) :
        if i > 0 :
            print(" ", end = "")
        print(value, end = "")
    print()
    
def bubbleSort(data) :
    flag = 1
    count = 0
    for i in range(len(data)):
        if not flag :
            break
        flag = 0
        for j in reversed(range(i + 1, len(data))):
            if data[j] < data[j - 1] :
                buf = data[j]
                data[j] = data[j - 1]
                data[j - 1] = buf
                flag = 1
                count += 1
    
    printData(data)
    print(count)
    
    
input()
data = [int(char) for char in input().split()]
bubbleSort(data)
