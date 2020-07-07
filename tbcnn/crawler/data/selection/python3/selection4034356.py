#選択ソート
#最小値を毎回計算して一番左にぶち込む直感的なソート

length = int(input())
list = list(map(int, input().split()))

count = 0
for i in range(length):
    minpos = i
    for j in range(i+1, length):
        if list[minpos] > list[j]:
            minpos = j

    if i != minpos:
        count += 1
    list[i], list[minpos] = list[minpos], list[i]

result = ''
for l in list:
    result += str(l) + ' '

print(result[:-1])
print(count)
