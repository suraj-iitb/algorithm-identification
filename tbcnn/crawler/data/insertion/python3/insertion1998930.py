n = int(input())
numbers = list(map(int, input().split()))

print(' '.join(str(x) for x in numbers))
for i in range(1, n):
    key = numbers[i]
    j = i - 1
    while 0 <= j and key < numbers[j]:
        numbers[j+1] = numbers[j]
        j -= 1
    numbers[j+1] = key
    print(' '.join(str(x) for x in numbers))
