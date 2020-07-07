n = int(input())
cards = list(map(int,input().split()))
cnt = 0
flag = 1
while flag:
    flag = 0
    for j in range(n-1,0,-1):

        if cards[j] < cards[j-1]:
            a = cards[j]
            b = cards[j-1]
            cards[j] = b
            cards[j-1] = a
            cnt += 1
            flag = 1

print(*cards)
print(cnt)
# #
# for j in range(10,1,-1):
#      print(j)



