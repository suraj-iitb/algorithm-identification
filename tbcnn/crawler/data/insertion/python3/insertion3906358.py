N = int(input())
list = [int(x) for x in input().split()] 
print(*list)

for i in range(1, N):
    v = list[i]
    j = i - 1
    while j >= 0 and list[j] > v:
        list[j+1] = list[j]
        j = j - 1
    list[j+1] = v
    print(*list)

