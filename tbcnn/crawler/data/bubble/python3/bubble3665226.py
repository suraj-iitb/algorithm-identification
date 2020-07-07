n = int(input())
li = list(map(int, input().split()))
i = 0

flag = True
while flag:
    flag = False
    for j in range(1, n)[::-1]:
        if li[j] < li[j-1]:
            tmp = li[j]
            li[j] = li[j-1]
            li[j-1] = tmp
            i += 1
            flag = True
            

print(str(li).replace(',', '')[1:-1])
print(i)
