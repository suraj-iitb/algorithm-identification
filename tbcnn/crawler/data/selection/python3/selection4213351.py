N = int(input())
seq = list(map(int, input().split()))
count = 0

for i in range(len(seq)):
    min = i
    for j in range(i, len(seq)):
        if seq[j] < seq[min]:
            min = j
    if seq[i] != seq[min]:
        seq[i], seq[min] = seq[min], seq[i]
        count += 1
    if seq == sorted(seq):
        print(*seq)
        print(count)
        break

