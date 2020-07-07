n = int(input())
list = list(map(int, input().split()))

print(' '.join(map(str,list)))
for i in range(1, n):
    insertNum = list[i]
    j = i - 1
    while j >= 0 and list[j] > insertNum:
        list[j+1] = list[j]
        j-=1
    list[j+1] = insertNum
    print(' '.join(map(str,list)))
