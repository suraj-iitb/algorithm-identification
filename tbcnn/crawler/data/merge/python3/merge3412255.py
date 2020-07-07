count = 0

n = int(input())
l = [int(i) for i in input().split()]


def merge_sort(a):
    if len(a) == 1:
        return [a[0]]
    mid = len(a) // 2
    l1 = merge_sort(a[:mid])
    l2 = merge_sort(a[mid:])
    merged = merge(l1, l2)
    return merged


def merge(l1, l2):
    global count
    len_l1 = len(l1)
    len_l2 = len(l2)
    l1c = l1.copy()
    l2c = l2.copy()

    l1c.append(10 ** 10)
    l2c.append(10 ** 10)

    i = 0
    j = 0
    r = []
    # print("l1", l1)
    # print("l2", l2)
    for k in range(len_l1 + len_l2):
        # print("i", i)
        # print("j", j)
        count += 1
        if l1c[i] <= l2c[j]:
            r.append(l1c[i])
            i += 1
        else:
            r.append(l2c[j])
            j += 1
    return r


r = merge_sort(l)
print(" ".join([str(i) for i in r]))
print(count)

