#バブルソート

length = int(input())
list = list(map(int, input().split()))

flag = 1
count = 0
while(flag):
    flag = 0
    for j in reversed(range(1, length)):
        if list[j] < list[j-1]:
            list[j], list[j-1] = list[j-1], list[j]
            flag = 1
            count += 1

result = ''
for l in list:
    result += str(l) + ' '

print(result[:-1])
print(count)
