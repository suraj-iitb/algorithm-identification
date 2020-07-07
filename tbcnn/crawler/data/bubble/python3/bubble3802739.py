#Bubble Sort

def printout(array, n):
    output = ""
    for i in range(n - 1):
        output += str(array[i]) + " "
    output += str(array[N - 1])
    print(output)


N = int(input())
array = [int(i) for i in input().split()]
count = 0;
for i in range(N):
    for j in reversed(range(i+1,N)):
        if (array[j-1] > array[j]):
            tmp = array[j]
            array[j] = array[j-1]
            array[j-1] = tmp
            count += 1
printout(array,N)
print(count)
