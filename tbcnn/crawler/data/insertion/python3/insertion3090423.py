def main():
    input()
    sequence = list(map(int, input().split()))
    inserted = False
    for i in range(len(sequence)):
        n = sequence.pop(i)
        for j in sequence[:i]:
            if n <= j:
                sequence.insert(sequence.index(j), n)
                inserted = True
                break
        if inserted is False:
            sequence.insert(i, n)
        else:
            inserted = False
        print(' '.join(map(str,sequence)))


if __name__ == "__main__":
    main()

