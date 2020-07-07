def bubbleSort(numlist):
    n = len(numlist)
    swaptime = 0
    for i in range(n):
        for j in range(n - 1, i, -1):
            if numlist[j] < numlist[j - 1]:
                swaptime += 1
                numlist[j], numlist[j - 1] = numlist[j - 1], numlist[j]
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
    swapnum =  bubbleSort(numlist)

    print_numlist(numlist)
    print(swapnum)
