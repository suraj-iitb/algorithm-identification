from typing import List, Tuple


def bubble_sort(A: List[int]) -> Tuple[List[int], int]:
    flag: bool = True
    count: int = 0

    while flag == True:
        flag = False
        for j in range(len(A) - 1, 0, -1):
            if A[j - 1] > A[j]:
                A[j - 1], A[j] = A[j], A[j - 1]
                flag = True
                count += 1

    return A, count


def main():
    _ = int(input())
    A: List[int] = list(map(int, input().split()))

    lst, count = bubble_sort(A)
    print(*lst, sep=" ")
    print(count)


if __name__ == "__main__":
    main()

