import sys

def bubble_sort(size, numbers):
    swap_count = 0

    for i in range(size):
        sorted = True
        for j in range(size - 1, i, -1):
            if numbers[j] < numbers[j - 1]:
                sorted = False
                swap_count += 1
                numbers[j], numbers[j - 1] = numbers[j - 1], numbers[j]
        if sorted:
            break

    return swap_count

def main(stdin=None, stdout=None):
    if stdin is None:
        stdin = sys.stdin
    if stdout is None:
        stdout = sys.stdout

    size = int(stdin.readline().strip())
    numbers = [int(x) for x in stdin.readline().strip().split(" ")]

    swap_count = bubble_sort(size, numbers)
    stdout.write(" ".join([str(x) for x in numbers]) + "\n")
    stdout.write(str(swap_count) + "\n")

main()
