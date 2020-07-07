cnt=int(input())
*card,=map(int,input().split())
for i in range(cnt):
	v=card[i]
	j=i-1
	while j>=0 and card[j]>v:
		card[j+1]=card[j]
		j-=1
	card[j+1]=v
	print(*card)
