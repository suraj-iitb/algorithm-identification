def selection_sort(seq):
    l = len(seq)
    cnt = 0
    for i in range(l):
        mi = i
        for j in range(i+1, l):
            if seq[j] < seq[mi]:
                mi = j
        if i is not mi:
            seq[i], seq[mi] = seq[mi], seq[i]
            cnt += 1
    return seq, cnt

n = int(input())
a = list(map(int, input().split()))
sorted_a, num_swap = selection_sort(a)
print(' '.join(map(str, sorted_a)))
print(num_swap)
