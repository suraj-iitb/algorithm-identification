num = int(input())
statements = input().split()
count = 0

for j in range(num):
    for i in range(num-1):
        statements[i] = int(statements[i])
        statements[i+1] = int(statements[i+1])
        if statements[i] > statements[i+1]:
            temp = statements[i] 
            statements[i] = statements[i+1]
            statements[i+1] = temp
            count += 1

print(*statements)
print(count)
