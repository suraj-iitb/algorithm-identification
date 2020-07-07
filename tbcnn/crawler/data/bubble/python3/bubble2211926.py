n = int(input())
sequence = [int(x) for x in input().split(' ')]

def pretty_sequence(sequence):
    n = len(sequence)
    for i in range(n-1):
        print(format(sequence[i]) + ' ', end='')
    print(sequence[n - 1])

def bubleSort(n, sequence):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(n-1, 0, -1):
            if sequence[i] < sequence[i-1]:
                tmp_val = sequence[i]
                sequence[i] = sequence[i-1]
                sequence[i-1] = tmp_val
                count += 1
                flag = 1
    return sequence, count

sequence, count = bubleSort(n, sequence)
pretty_sequence(sequence)
print(count)
