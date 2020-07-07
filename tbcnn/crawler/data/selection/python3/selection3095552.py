def main():
    input()
    times = 0
    sequence = list(map(int, input().split()))
    for i in range(len(sequence)):
        mini = i
        for j in range(i, len(sequence)):
            if sequence[j] < sequence[mini]:
                mini = j
        if i != mini:
            times += 1
        sequence[i], sequence[mini] = sequence[mini], sequence[i]
    print(' '.join(map(str, sequence)))
    print(times)


if __name__ == "__main__":
    main()

