num = int(input())
cards = [int(i) for i in input().split()]

def bubble_sort(num, cards):
	flag = 1
	count = 0
	while flag:
		flag = 0
		for j in range(num-1, 0, -1):
			if cards[j] < cards[j-1]:
				card_tmp = cards[j]
				cards[j] = cards[j-1]
				cards[j-1] = card_tmp
				flag = 1
				count += 1
	return output(cards), count

def output(cards):
	sorting = [str(i) for i in cards]
	return (" ".join(sorting))

output, count = bubble_sort(num, cards)
print(output)
print(count)
