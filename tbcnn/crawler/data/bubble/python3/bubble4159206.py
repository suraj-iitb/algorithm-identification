# Algorithms and Data Structures 1
# Bubble Sort
# Name: Ryuya Asada
# ID: s1260064


def BubbleSort(A: list):
    number_of_swaps = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(len(A)-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                number_of_swaps += 1
    print(*A, sep=" ")
    print(number_of_swaps)


def main():
    length = int(input())
    A = [int(e) for e in input().split(" ")]
    BubbleSort(A)

if __name__ == "__main__":
    main()

