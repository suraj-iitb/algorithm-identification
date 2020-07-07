n = int(input())

arrey = [int(i) for i in input().split()]

for i in range(n):
    v = arrey[i]
    j = i - 1
    while j >= 0 and arrey[j] > v:
        arrey[j+1] = arrey[j]
        j = j - 1
        arrey[j+1] = v
    for k in range(n):
        print(arrey[k]) if k == n-1 else print(str(arrey[k])+' ',end='')
