import copy

def quicksort(li, ini_i, length):
    # print(li, ini_i, length)
    if ini_i < length:
        next_len = partition(li, ini_i, length)
        # print(next_len)
        quicksort(li, ini_i, next_len - 1)
        quicksort(li, next_len + 1, length)

def partition(li, ini_i, length):
    target = li[length][1]
    # print(target, li, ini_i, length)
    for i in range(ini_i, length):
        if li[i][1] <= target:
            li[ini_i], li[i] = li[i], li[ini_i]
            ini_i += 1
    # print(f"its {ini_i}")
    li[ini_i], li[length] = li[length], li[ini_i]
    return ini_i

length = int(input())
li = []
base_li = []
for i in range(length):
    t = input().split(" ")
    t[1] = int(t[1])
    base_li.append(t)
li = copy.deepcopy(base_li)

quicksort(li, 0, length - 1)

for i in range(length - 1):
    if li[i + 1][1] == li[i][1]:
        if base_li.index(li[i + 1]) < base_li.index(li[i]):
            print("Not stable")
            break
else:
    print("Stable")
for i, n in enumerate(li):
    print(*n)

