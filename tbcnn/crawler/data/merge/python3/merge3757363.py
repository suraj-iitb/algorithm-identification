import sys
from typing import List


COMP_NUM = 0


def merge(elements: List[int], left: int, mid: int, right: int) -> None:
    global COMP_NUM
    n1 = mid - left
    n2 = right - mid
    left_array = [0] * (n1 + 1)
    right_array = [0] * (n2 + 1)
    left_array[0:n1] = elements[left:left + n1]
    left_array[n1] = sys.maxsize
    right_array[0:n2] = elements[mid:mid + n2]
    right_array[n2] = sys.maxsize

    i = 0
    j = 0
    for k in range(left, right):
        COMP_NUM += 1
        if left_array[i] <= right_array[j]:
            elements[k] = left_array[i]
            i += 1
        else:
            elements[k] = right_array[j]
            j += 1


def merge_sort(elements: List[int], left: int, right: int) -> None:
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(elements, left, mid)
        merge_sort(elements, mid, right)
        merge(elements, left, mid, right)


if __name__ == "__main__":
    n = int(input())
    elements = list(map(lambda x: int(x), input().split()))
    merge_sort(elements, 0, len(elements))
    print(" ".join([str(elem) for elem in elements]))
    print(f"{COMP_NUM}")

