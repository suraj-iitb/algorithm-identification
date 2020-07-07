# Algorithms and Data Structures 1
# Selection Sort
# Name: Ryuya Asada
# ID: s1260064


def SelectionSort(A: list):
    number_of_actual_swaps = 0
    for i in range(0, len(A)):
        minj = i
        for j in range(i, len(A)):
            if A[j] < A[minj]:
                minj = j

        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            number_of_actual_swaps += 1

    print(*A, sep=" ")
    print(number_of_actual_swaps)


def main():
    length = int(input())
    A = [int(e) for e in input().split()]
    SelectionSort(A)


if __name__ == "__main__":
    main()

