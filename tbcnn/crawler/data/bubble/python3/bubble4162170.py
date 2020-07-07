def BubbleSort(seq):
    count = 0

    for i in range(len(seq)):
        for j in reversed(range(i + 1, len(seq))):
            if seq[j] < seq[j - 1]:
                seq[j], seq[j - 1] = seq[j - 1], seq[j]
                count += 1

    print(*seq)
    print(count)

def main():
    n = input()
    seq = [int(a) for a in input().split()]
    BubbleSort(seq)

main()
