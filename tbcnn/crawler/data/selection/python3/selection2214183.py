def pretty_sequence(sequence):
    n = len(sequence)
    for i in range(n-1):
        print(format(sequence[i]) + ' ', end='')
    print(sequence[n - 1])

n = int(input())
sequence = [int(x) for x in input().split(' ')]


def selectionsort(seq, x):
    count = 0
    for i in range(x):
        minj = i
        for j in range(i, x):
            if seq[j] < seq[minj]:
                minj = j
        if seq[i] != seq[minj]:
            tmp_val = seq[i]
            seq[i] = seq[minj]
            seq[minj] = tmp_val
            count += 1
    return seq, count

sequence, count = selectionsort(sequence, n)
pretty_sequence(sequence)
print(count)
