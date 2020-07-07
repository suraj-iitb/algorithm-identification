from typing import List, Tuple


def selection_sort(A: List[int]) -> Tuple[List[int], int]:
    count: int = 0

    for i in range(len(A)):
        min_j: int = i
        for j in range(i, len(A)):
            if A[j] < A[min_j]:
                min_j = j
        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            count += 1

    return A, count


def main():
    _ = input()
    A: List[int] = list(map(int, input().split()))

    lst, count = selection_sort(A)
    print(*lst, sep=" ")
    print(count)


if __name__ == "__main__":
    main()

