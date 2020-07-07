def selectionSort(numlist):
    n = len(numlist)
    swaptime = 0
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if numlist[j] < numlist[min_index]:
                min_index = j
        if min_index != i:
            numlist[i], numlist[min_index] = numlist[min_index], numlist[i]
            swaptime += 1
    return swaptime

def print_numlist(numlist):
    if len(numlist) == 1:
        print(numlist[0])
    else:
        for i in range(0, len(numlist) - 1):
            print(numlist[i], end = ' ')
        print(numlist[-1])

if __name__ == '__main__':
    n = int(input())
    numlist = [int(i) for i in input().replace('\n', '').split(' ')]
    swapnum =  selectionSort(numlist)

    print_numlist(numlist)
    print(swapnum)
