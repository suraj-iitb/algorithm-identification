def InsertionSort(seq):
    print(*seq)
    for i in range(len(seq) - 1):
        j = i

        while j >= 0:
            if seq[j + 1] < seq[j]:
                seq[j + 1], seq[j] = seq[j], seq[j + 1]
                
            j -= 1 

        print(*seq)

def main():
    n = int(input())
    seq = [int(a) for a in input().split()]
    InsertionSort(seq)

main()
