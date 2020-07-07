N = int(input())
Numbers = list(map(int, input().split()))
Flag = True
count = 0
while Flag:
    Flag = False
    for j in range(N - 1, 0, -1):
        if Numbers[j] < Numbers[j - 1]:
            Numbers[j], Numbers[j - 1] = Numbers[j - 1], Numbers[j]
            count += 1
            Flag = True
print(' '.join(list(map(str, Numbers))))
print(count)

