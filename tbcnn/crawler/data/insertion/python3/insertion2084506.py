N = int(input())
seq = list(map(int, input().split()))
print(" ".join(map(str, seq)))
for i in range(1, N):
    key = seq[i]
    j = i-1
    while j >= 0 and seq[j] > key:
        seq[j+1] = seq[j]
        j -= 1
    seq[j+1] = key
    print(" ".join(map(str, seq)))
