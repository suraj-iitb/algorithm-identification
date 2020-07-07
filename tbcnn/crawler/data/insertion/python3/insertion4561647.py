N = int(input())
cards = list(map(int,input().split()))
print(" ".join(map(str,cards)))

for i in range(1,N):
    tmp = cards[i]
    j = i - 1
    while j >= 0 and tmp < cards[j]:
        cards[j+1] = cards[j]
        cards[j] = tmp
        j -= 1
    print(" ".join(map(str,cards)))

