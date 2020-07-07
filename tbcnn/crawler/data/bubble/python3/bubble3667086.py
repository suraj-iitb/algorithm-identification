length = int(input())
List = list(map(int,input().split()))

count = 0
state = 1

while state:
    state = 0
    for i in range(length-1):
        if List[i] > List[i+1]:
            stuck = List[i]
            List[i] = List[i+1]
            List[i+1] = stuck
            state = 1
            count += 1

for i in range(length):
    if i == length - 1:
        print(List[length-1])
    else: print(List[i],end=' ')
print(count)
