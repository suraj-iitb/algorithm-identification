def bubble_sort(elems: list) -> list:
    swap_num = 0
    for i in range(0, len(elems)):
        for j in range(len(elems) - 1, i, -1):
            if elems[j] < elems[j - 1]:
                elems[j], elems[j - 1] = elems[j - 1], elems[j]
                swap_num += 1
    return [elems, swap_num]


if __name__ == "__main__":
    elem_num = int(input())
    elems = list(map(lambda x: int(x), input().split()))
    elems, swap_num = bubble_sort(elems)
    print(" ".join([str(elem) for elem in elems]))
    print(f"{swap_num}")

