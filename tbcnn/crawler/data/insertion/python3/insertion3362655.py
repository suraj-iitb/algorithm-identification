

def printArrLine( arr ):
    print(' '.join(list(map(str,arr))))
    
def inputArrLine():
    return [int(i) for i in input().split()]
    
def insert( arr ):
    n = len(arr)
    printArrLine(arr)
    for i in range(1,n):
        v = arr[i]
        j = i-1
        while j >= 0 and arr[j] > v:
            arr[j+1] = arr[j]
            j = j-1
        arr[j+1] = v
        printArrLine(arr)

n = int(input())

ar = inputArrLine()

insert(ar)


