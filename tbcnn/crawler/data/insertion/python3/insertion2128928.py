def insertion_sort(seq):
    print(' '.join(map(str, seq)))
    for i in range(1, len(seq)):
        key = seq[i]
        j = i - 1
        while j >= 0 and seq[j] > key:
            seq[j+1] = seq[j]
            j -= 1
        seq[j+1] = key
        print(' '.join(map(str, seq)))
    return seq

n = int(input())
seq = list(map(int, input().split()))
insertion_sort(seq)
