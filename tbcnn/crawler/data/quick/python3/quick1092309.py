from copy import deepcopy

def Partition(A, p, r):
    x = A[r][1]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i+1

def Quicksort(A, p, r):
    if p < r:
        q = Partition(A, p, r)
        Quicksort(A, p, q-1)
        Quicksort(A, q+1, r)


n = int(input())
cards = []
for i in range(n):
    card = input().split()
    card[1] = int(card[1])
    cards.append(card)
prev_cards = deepcopy(cards)
prev_cards.sort(key=lambda card: card[1])

Quicksort(cards, 0, n-1)

if cards == prev_cards:
    print("Stable")
else:
    print("Not stable")

for card in cards:
    print(' '.join(map(str, card)))
