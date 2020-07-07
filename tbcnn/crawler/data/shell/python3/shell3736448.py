from typing import List


def insertion_sort(elems: List[int], interval: int) -> int:
    cnt = 0
    for i in range(interval, len(elems)):
        v = elems[i]
        j = i - interval
        while (j >= 0) and (elems[j] > v):
            elems[j + interval] = elems[j]
            j = j - interval
            cnt += 1
        elems[j + interval] = v
    return cnt


def get_intervals(num: int) -> List[int]:
    intervals = []
    h = 1
    intervals.append(h)
    while True:
        h = 3 * h + 1
        if h >= num:
            break
        intervals.append(h)
    return sorted(intervals, reverse=True)


if __name__ == "__main__":
    elem_num = int(input())
    elems = [int(input()) for elem in range(elem_num)]

    cnt = 0
    intervals = get_intervals(elem_num)
    for interval in intervals:
        cnt += insertion_sort(elems, interval)

    print(f"{len(intervals)}")
    print(" ".join([str(elem) for elem in intervals]))
    print(f"{cnt}")
    for elem in elems:
        print(f"{elem}")

