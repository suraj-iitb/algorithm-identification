n = int(input())
li = list(map(int, input().split()))

def b_s(li):
    num = 0
    for index in range(len(li)):
        for j in range(len(li) - 1, index, -1):
            if li[j] < li[j-1]:
                li[j], li[j-1] = li[j-1], li[j]
                num += 1
    return li, num

li, num = b_s(li)
print(*li)
print(num)

