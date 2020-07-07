def printData(data):
    for d in data:
        val = f'{d}'
        if data[-1] != d:
            end = " "
        else:
            end = "\n"
        print(f'{d}',end=end)

num = int(input())
data = list(map(int,input().split()))

printData(data)

for i in range(1,num):
    v = data[i]
    j = i -1 
    while j >= 0 and data[j] > v:
        data[j+1] = data[j]
        j -= 1
    data[j+1] = v
    printData(data)

