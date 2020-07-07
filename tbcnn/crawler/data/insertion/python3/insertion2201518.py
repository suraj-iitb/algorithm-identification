n = int(input())
sequence = input().split(' ')
sequence = [int(x) for x in sequence]
for h in range(n - 1):
    print(format(sequence[h]) + ' ', end='')
print(sequence[n - 1])

for i in range(1, n):
    v = sequence[i]
    j = i - 1
    while j >= 0 and sequence[j] > v:
        sequence[j+1] = sequence[j]
        j -= 1
    sequence[j+1] = v
    for k in range(n-1):
        print(format(sequence[k]) + ' ', end='')
    print(sequence[n-1])
