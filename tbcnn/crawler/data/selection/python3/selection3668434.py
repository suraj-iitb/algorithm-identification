length = int(input())
List = list(map(int, input().split()))

minimum = List[0]
count = 0

for i in range(length):
    minj = i
    for j in range(i,length):
        if List[j] < List[minj]:
            minj = j
    if List[minj] != List[i]:
        minimum = List[minj]
        List[minj] = List[i]
        List[i] = minimum
        count += 1

print(*List)
print(count)
