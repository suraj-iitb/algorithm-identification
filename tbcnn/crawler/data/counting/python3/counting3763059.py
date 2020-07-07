from typing import List


def counting_sort(elements: List[int]) -> List[int]:
    C = [0] * (max(elements) + 1)
    B = [0] * (len(elements) + 1)

    for elem in elements:
        C[elem] += 1
    for i in range(1, len(C)):
        C[i] += C[i - 1]
    for elem in elements[::-1]:
        B[C[elem]] = elem
        C[elem] = C[elem] - 1
    return B[1:]


if __name__ == "__main__":
    _ = int(input())
    elements = list(map(lambda x: int(x), input().split()))

    sorted_elements = counting_sort(elements)

    print(" ".join([str(elem) for elem in sorted_elements]))

