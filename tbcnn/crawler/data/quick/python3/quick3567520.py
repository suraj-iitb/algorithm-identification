def partition(A, p, r):
    x = A[r][0]
    i = p-1
    for j in range(p, r):
        if A[j][0] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]

    A[i+1], A[r] = A[r], A[i+1]
    return i+1


def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)


if __name__ == "__main__":
    import sys
    from operator import itemgetter
    n = int(input())
    cards1, cards2 = [], []
    for i, card in enumerate((l.strip()) for l in sys.stdin):
        cards1.append(card)
        cards2.append((int(card[2:]), i))

    quicksort(cards2, 0, n-1)
    print("Stable" if all(i1 < i2 for (n1, i1), (n2, i2) in zip(cards2, cards2[1:]) if n1 == n2)
          else "Not stable")
    print(*(cards1[i] for i in map(itemgetter(1), cards2)), sep="\n")
