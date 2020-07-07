# バブルソート
def bubbleSort(list, n):
    cnt = 0  # 要素の交換回数
    for i in range(n-1):
        for j in reversed(range(i+1, n)):
            if list[j] < list[j-1]:
                list[j], list[j-1] = list[j-1], list[j]
                cnt += 1
    return cnt

N = int(input())
array = list(map(int, input().split()))
ans = bubbleSort(array, N)

print(array[0], end="")
for i in range(1, N):
    print(" %d" % array[i], end="")
print("\n%d" % ans)
