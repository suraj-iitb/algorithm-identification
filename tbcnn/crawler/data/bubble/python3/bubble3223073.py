import sys

def main():
    #inputs = [5, 3, 2, 4, 1]
    #inputslen = len(inputs) - 1

    inputslen = int(sys.stdin.readline().rstrip())
    inputs= sys.stdin.readline()

    sortvalue = [int(i) for i in inputs.split()]
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(1, inputslen):
            j = inputslen - i
            compvalue = sortvalue[j]
            if compvalue < sortvalue[j-1]:
                sortvalue[j] = sortvalue[j-1]
                sortvalue[j-1] = compvalue
                flag = 1
                count += 1

    printvalue = map(str, sortvalue)
    print(' '.join(printvalue))
    print(count)

if __name__ == '__main__':
    main()
