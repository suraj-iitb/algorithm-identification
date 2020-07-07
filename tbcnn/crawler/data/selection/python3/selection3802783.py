#selection sort


def printout(array,n):
    output = ""
    for i in range(n-1):
        output += str(array[i]) + " "
    output += str(array[N-1])
    print(output)


def linearsearch(subarray):
    # return index of minimum array element
    min = subarray[0]
    min_index = 0;
    for i in range(1,len(subarray)):
        if min > subarray[i]:
            min = subarray[i]
            min_index = i
    return min_index


N = int(input())
array = [int(i) for i in input().split()]

count,index,tmp = 0,0,0

for i in range(N):
    index = linearsearch(array[i:]) + i

    if index != i:
        #swap
        tmp = array[index]
        array[index] = array[i]
        array[i] = tmp
        count += 1

printout(array,N)
print(count)
