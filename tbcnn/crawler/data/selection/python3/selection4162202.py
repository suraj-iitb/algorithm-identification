def SelectionSort(seq):
    swp_cnt = 0
    
    for i in range(0, len(seq)):
        idx = i

        for j in range(i, len(seq)):
            if seq[idx] > seq[j]:
                idx = j

        if idx != i:
            seq[i], seq[idx] = seq[idx], seq[i]        
            swp_cnt += 1

    print(*seq)
    print(swp_cnt)

def main():
    n = input()
    seq = [int(a) for a in input().split()]
    SelectionSort(seq)

main()
