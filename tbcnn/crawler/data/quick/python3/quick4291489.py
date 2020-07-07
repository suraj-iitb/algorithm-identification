import sys
sys.setrecursionlimit(2000000000)

N = int(input())
origin_list = [input().split() for _ in range(N)]
card_list = origin_list[:]
card_list2 = sorted(card_list[:], key=lambda x:x[1])

def partition(A, p, r):
    x = int(A[r][1])
    i = p - 1

    for j in range(p, r):
        if int(A[j][1]) <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i+1


def quickSort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quickSort(A, p, q-1)
        quickSort(A, q+1, r)

quickSort(card_list, 0, len(card_list)-1)


if card_list == card_list2:
    print('Stable')
else:
    print('Not stable')

for item in card_list:
    print(*item)
