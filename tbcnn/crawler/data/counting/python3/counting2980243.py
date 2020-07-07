def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    counters = [0] * 10001
    sortedNumbers = [0] * n
    for number in numbers:
        counters[number] += 1

    for i in range(1, 10001, 1):
        counters[i] += counters[i - 1]

    for i in range(n - 1, -1, -1):
        sortedNumbers[counters[numbers[i]] - 1] = numbers[i]
        counters[numbers[i]] -= 1

    print(' '.join(map(str, sortedNumbers)))

if __name__ == '__main__':
    main()

