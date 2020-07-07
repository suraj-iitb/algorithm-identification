n = int(input())
suits = [0] * n
ranks = [0] * n
orders = [0] * n
for i in range(n):
    suit, rank = input().split()
    suits[i] = suit
    ranks[i] = int(rank)
    orders[i] = i

def quicksort(p, r):
    if p < r:
        q = partition(p, r)
        quicksort(p, q-1)
        quicksort(q+1, r)

def partition(p, r):
    global suits, ranks, orders
    x = ranks[r]
    i = p - 1
    for j in range(p, r):
        if ranks[j] <= x:
            i += 1
            suits[i], suits[j] = suits[j], suits[i]
            ranks[i], ranks[j] = ranks[j], ranks[i]
            orders[i], orders[j] = orders[j], orders[i]
    i += 1
    suits[i], suits[r] = suits[r], suits[i]
    ranks[i], ranks[r] = ranks[r], ranks[i]
    orders[i], orders[r] = orders[r], orders[i]
    return i

quicksort(0, n-1)

for i in range(1, n):
    if ranks[i] == ranks[i-1] and orders[i] < orders[i-1]:
        print('Not stable')
        break
else:
    print('Stable')

for i in range(n):
    print(suits[i], ranks[i])

