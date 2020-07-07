def InputData():
    
    sequence_len = int(input())
    sequence = [None] + [int(a) for a in input().split(" ")]

    return sequence_len, sequence

def countingSort(sequence, k, sequence_len):
    
    B = [None]*(sequence_len+1)
    C = [0]*k
    
    for j in range(1, sequence_len+1):
        C[sequence[j]] += 1
    
    for i in range(1, k):
        C[i] = C[i] + C[i-1]
    
    for j in range(sequence_len, 0, -1):
        B[C[sequence[j]]] = sequence[j]
        C[sequence[j]] -= 1

    return B

def PrintOut(sequence):
    print(' '.join( map(str, sequence)))

def main():
    [sequence_len, sequence] = InputData()
    sequence_out = countingSort(sequence, 10000, sequence_len)
    PrintOut(sequence_out[1:])

if __name__=="__main__":
    main()
