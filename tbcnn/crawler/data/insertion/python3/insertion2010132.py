length = int(input())
eles = [int(i) for i in input().split()]

for i in range(length):
    val = eles[i]
    j = i - 1
    while j >= 0 and eles[j] > val:
        eles[j+1] = eles[j]
        j -= 1
    eles[j+1] = val
    print(*eles)
