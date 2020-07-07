if __name__ == "__main__":
    elem_num = int(input())
    elems = list(map(lambda x: int(x), input().split()))
    print(" ".join([str(elem) for elem in elems]))  # Initial state.
    for i in range(1, elem_num):
        key = elems[i]
        j = i - 1
        while j >= 0 and elems[j] > key:
            elems[j + 1] = elems[j]
            j -= 1
        elems[j + 1] = key
        print(" ".join([str(elem) for elem in elems]))  # Each sorting steps.

