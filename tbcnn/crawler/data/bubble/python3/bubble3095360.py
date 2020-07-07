def main():
    input()
    times = 0
    sequence = list(map(int, input().split()))
    for i in range(len(sequence)):
        for j in range(len(sequence)-1, i, -1):
            if sequence[j-1] > sequence[j]:
                tmp = sequence[j]
                sequence[j] = sequence[j-1]
                sequence[j-1] = tmp
                times += 1
    print(' '.join(map(str, sequence)))
    print(times)


if __name__ == "__main__":
    main()

