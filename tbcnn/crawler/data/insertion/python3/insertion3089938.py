n = int(input())
cards = list(map(int, input().split()))

for i in range(n):
    v = cards[i]
    j = i-1
    while j >= 0 and cards[j] > v:
        cards[j+1] = cards[j]
        j -= 1
    cards[j+1] = v
    print(' '.join(map(str, cards)))
