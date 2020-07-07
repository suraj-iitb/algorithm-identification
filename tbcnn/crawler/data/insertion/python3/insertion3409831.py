n = int(input())
cards = list(map(int,input().split()))
print(*cards)
for i in range(1,n):
    v = cards[i]
    j = i-1
    while j >= 0 and cards[j] > v:
        cards[j+1] = cards[j]
        j -= 1
    cards[j+1] = v
    print(*cards)

