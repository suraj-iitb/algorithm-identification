N = int(input())
#print(N)
card = list(map(int, input().split()))
#print(card)

for i in range(N):
    v = card[i]
    j = i - 1
    while j >= 0 and card[j] > v:
        card[j+1] = card[j]
        j = j -1
    card[j+1] = v
    #print(card)
    card_str = ""
    
    for k in range(N):
        card_str += str(card[k])
        card_str += " "
    
    print(card_str[:-1])

    
