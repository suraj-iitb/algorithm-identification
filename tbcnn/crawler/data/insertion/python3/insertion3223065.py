import sys

def main():
    inputslen = int(sys.stdin.readline().rstrip())
    inputs= sys.stdin.readline()

    sortvalue = [int(i) for i in inputs.split()]
    for i in range(1, inputslen):
        printvalue = map(str, sortvalue)
        print(' '.join(printvalue))

        compvalue = sortvalue[i]
        j = i - 1
        while j >= 0 and sortvalue[j] > compvalue:
            sortvalue[j+1] = sortvalue[j]
            j -= 1
        sortvalue[j+1] = compvalue

    printvalue = map(str, sortvalue)
    print(' '.join(printvalue))

if __name__ == '__main__':
    main()
