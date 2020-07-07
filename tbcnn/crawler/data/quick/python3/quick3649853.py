def partition(A, p, r):
    COLUMN_SORT = 1

    global flag_stable

    x = A[r][COLUMN_SORT]
    i = p - 1

    for j in range(p, r):
        if A[j][COLUMN_SORT] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]

    q = i + 1
    A[q], A[r] = A[r], A[q]

    for i in range(q + 1, r):
        if A[r] > A[i]:
            flag_stable = False

    return q


def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)


# INPUT
n = int(input())

list_card = []
for _ in range(n):
    suit, num = input().split()
    list_card.append([suit, int(num)])


# PROCESS
flag_stable = True

quicksort(list_card, 0, n-1)


# OUTPUT
if flag_stable:
    print("Stable")
else:
    print("Not stable")

for card in list_card:
    print(*card)

