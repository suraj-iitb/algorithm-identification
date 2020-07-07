def buble_sort(seq):
    l = len(seq)
    cnt = 0
    for i in range(l):
        for j in range(i+1, l)[::-1]:
            if seq[j] < seq[j-1]:
                seq[j], seq[j-1] = seq[j-1], seq[j]
                cnt += 1
    return seq, cnt


n = int(input())
a = list(map(int, input().split()))
sorted_a, num_swap = buble_sort(a)
print(' '.join(map(str, sorted_a)))
print(num_swap)
