def bubbleSort(a, n):
    number = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(n - 1, 0, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                flag = 1
                number += 1
    return number


n = int(input())
ls = list(map(int, input().split()))
num = bubbleSort(ls, n)
for i in range(len(ls)):
    if i:
        print(" ", end="")
    print(ls[i], end="")
print()
print(num)
