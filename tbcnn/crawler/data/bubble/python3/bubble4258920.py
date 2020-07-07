def Bubble_Sort(n, L):
    flag = True
    j = 0
    count = 0
    while flag:
        flag = False
        for i in range(n-1, j, -1):
            if L[i] < L[i - 1]:
                L[i], L[i - 1] = L[i - 1], L[i]
                count += 1
                flag = True
    return count

n = int(input())
L = list(map(int, input().split()))

s = Bubble_Sort(n, L)
print(*L)
print(s)
