def insertion_sort(seq):
    n = len(seq)
    for i in range(n):
        v = seq[i]
        j = i-1
        while j >= 0 and seq[j] > v:
            seq[j+1] = seq[j] #vの入る候補がindexのi-1
            j -= 1
        seq[j+1] = v
        print(seq[0], end='')
        for k in range(1, n):
            print(' '+str(seq[k]), end='')
        print()

n = int(input())
seq = list(map(int, input().split()))
insertion_sort(seq)
