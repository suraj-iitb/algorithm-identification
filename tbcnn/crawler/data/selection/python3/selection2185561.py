n = int(input())
arrey = [int(i) for i in input().split()]
count = 0

for i in range(len(arrey)):
    minj = i
    change = False
    for j in range(i+1, len(arrey)):
        if arrey[minj] > arrey[j]:
            minj = j
            change = True
    if change:
        arrey[i], arrey[minj] = arrey[minj], arrey[i]
        count += 1

for i in range(len(arrey)):
    print(str(arrey[i])+' ',end='') if i != len(arrey)-1 else print(arrey[i])
print(count)
