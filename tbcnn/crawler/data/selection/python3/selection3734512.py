def selection_sort(elems: list) -> list:
    swap_num = 0
    for i in range(0, len(elems)):
        mini = i
        for j in range(i + 1, len(elems)):
            if elems[j] < elems[mini]:
                mini = j
        if i != mini:
            elems[i], elems[mini] = elems[mini], elems[i]
            swap_num += 1
    return [elems, swap_num]


if __name__ == "__main__":
    elem_num = int(input())
    elems = list(map(lambda x: int(x), input().split()))
    elems, swap_num = selection_sort(elems)
    print(" ".join([str(elem) for elem in elems]))
    print(f"{swap_num}")

