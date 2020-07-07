factor = int(input())
numbers = list(map(int, input().split()))

def bublesort(array, n):
    counter = 0
    flag = 1
    while(flag):
        i=0
        flag=0
        temp = 0
        for j in range(len(array)-1, i, -1):
            if array[j] < array[j-1]:
                temp = array[j]
                array[j] = array[j-1]
                array[j-1] = temp
                flag = 1
                counter += 1
        i += 1
    return counter


repetition = bublesort(numbers, factor)
print(" ".join(list(map(str,numbers))))
print(repetition)

