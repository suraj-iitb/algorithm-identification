import copy
from typing import List, Tuple


def partition(elements: List[Tuple[str, int]], start_idx: int, pivot_idx: int) -> int:
    pivot = elements[pivot_idx][1]
    i = start_idx - 1

    for j in range(start_idx, pivot_idx):
        if elements[j][1] <= pivot:
            i += 1
            elements[i], elements[j] = elements[j], elements[i]
    elements[i + 1], elements[pivot_idx] = elements[pivot_idx], elements[i + 1]

    return i + 1


def quick_sort(elements: List[Tuple[str, int]], p: int, r: int) -> None:
    if p < r:
        q = partition(elements, p, r)
        quick_sort(elements, p, q - 1)
        quick_sort(elements, q + 1, r)


if __name__ == "__main__":
    n = int(input())
    elements = [("", 0)] * n
    for i in range(n):
        element = input().split()
        elements[i] = (element[0], int(element[1]))

    elements_copy = copy.deepcopy(elements)
    quick_sort(elements, 0, n - 1)

    for i in range(n - 1):
        if elements[i][1] == elements[i + 1][1]:
            if elements_copy.index(elements[i]) > elements_copy.index(elements[i + 1]):
                print("Not stable")
                break
    else:
        print("Stable")

    for elem in elements:
        print(f"{elem[0]} {elem[1]}")

