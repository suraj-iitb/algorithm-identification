import sys

def selection_sort(size, numbers):
    swap_count = 0

    for i in range(size):
        minindex = i
        for j in range(i + 1, size):
            if numbers[j] < numbers[minindex]:
                minindex = j

        if i != minindex:
            swap_count += 1
            numbers[i], numbers[minindex] = numbers[minindex], numbers[i]

    return swap_count

def main(stdin=None, stdout=None):
    if stdin is None:
        stdin = sys.stdin
    if stdout is None:
        stdout = sys.stdout

    size = int(stdin.readline().strip())
    numbers = [int(x) for x in stdin.readline().strip().split(" ")]

    swap_count = selection_sort(size, numbers)
    stdout.write(" ".join([str(x) for x in numbers]) + "\n")
    stdout.write(str(swap_count) + "\n")

main()
