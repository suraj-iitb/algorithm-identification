n = int(input())
bubble=list(map(int,input().split()))
count = 0
for i in  range(len(bubble)):
    for a in range(len(bubble)-1):
        if (bubble[a] > bubble[a+1]):
            bubble[a], bubble[a+1] = bubble[a+1], bubble[a]
            count = count+1
print(*bubble)
print(count)
