N = int(input())
seq = list(map(int, input().split()))

def BubbleSort(seq):
    count = 0
    for i in range(N):
        for j in range(1, N):
            if seq[j] < seq[j-1]:
                swp = seq[j]
                seq[j], seq[j-1] = seq[j-1], swp
                count += 1

    print(" ".join([str(x) for x in seq]))
    print(count)

BubbleSort(seq)
