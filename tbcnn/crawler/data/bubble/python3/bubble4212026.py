N = int(input())

seq = list(map(int, input().split()))

count = 0

print(*sorted(seq))

for i in range(len(seq)):
    for j in reversed(range(i + 1, len(seq))):
        if seq[j] < seq[j - 1]:
            seq[j], seq[j - 1] = seq[j - 1], seq[j]
            count += 1

print(count)
