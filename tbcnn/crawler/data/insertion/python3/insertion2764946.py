num = int(input())
cards = [int(i) for i in input().split()]

def insertion_sort(num, cards):
	for i in range(num):
		v = cards[i]
		j = i - 1
		while j >= 0 and cards[j] > v:
			cards[j+1] = cards[j]
			j -= 1
		cards[j+1] = v
		output(cards)

def output(cards):
	sorting = [str(i) for i in cards]
	print(" ".join(sorting))

insertion_sort(num, cards)
