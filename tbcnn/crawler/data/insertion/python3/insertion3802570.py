#insertion sort
def printout(array,n):
    output = ""
    for i in range(n-1):
        output += str(array[i]) + " "
    output += str(array[N-1])
    print(output)

N = int(input())
array = [int(i) for i in input().split()]
printout(array,N)

for i in range(1,N):
    a = array[i]
    for j in reversed(range(0,i)):
        if (a < array[j]):
            array[j+1] = array[j]
            array[j] = a
        else:
            break;
    printout(array, N)
