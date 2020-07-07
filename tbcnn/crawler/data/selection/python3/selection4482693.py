count = 0
n = int(input())
list1 = list(map(int, input().split()))
for i in range(n):
    m = i
    for j in range(i, n):
        if list1[j] < list1[m]:
            m = j
    if m != i:
        list1[i], list1[m] = list1[m], list1[i]
        count += 1
print(*list1)
print(count)
