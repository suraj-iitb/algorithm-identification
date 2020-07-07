import sys

def main():
    inputslen = int(sys.stdin.readline().rstrip())
    inputs= sys.stdin.readline()

    sortvalue = [int(i) for i in inputs.split()]
    count = 0
    for i in range(0, inputslen-1):

        minidx = i
        for j in range(i, inputslen):
            if sortvalue[j] < sortvalue[minidx]:
                minidx = j
        if sortvalue[minidx] != sortvalue[i]:
            minvalue = sortvalue[minidx]
            sortvalue[minidx] = sortvalue[i]
            sortvalue[i] = minvalue
            count += 1

    printvalue = map(str, sortvalue)
    print(' '.join(printvalue))
    print(count)

if __name__ == '__main__':
    main()
