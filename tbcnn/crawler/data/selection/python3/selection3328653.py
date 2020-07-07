n = int(input())
s = list(map(int, input().strip().split(' ')))

count = 0

for i in range(n):
    minj = i
    for j in range(i + 1, n):
        if s[j] < s[minj]:
            minj = j
    
    if minj != i:
        count += 1
    
    s[i], s[minj] = s[minj], s[i]

for i in range(n):
    if i != n - 1:
        print(s[i], end = ' ')
    else:
        print(s[i])

print(count)
