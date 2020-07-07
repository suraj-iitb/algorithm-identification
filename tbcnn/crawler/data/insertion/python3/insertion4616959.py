def main():
    card_num = int(input())
    cards = list(map(int, input().split()))
    
    res = " ".join([str(n) for n in cards])
    print(res)
    
    for i in range(1, card_num):
        v = cards[i]
        j = i - 1
        while j >= 0 and cards[j] > v:
            cards[j + 1] = cards[j]
            j -= 1
        cards[j + 1] = v
        
        res = " ".join([str(n) for n in cards])
        print(res)

if __name__ == '__main__':
    main()
    
