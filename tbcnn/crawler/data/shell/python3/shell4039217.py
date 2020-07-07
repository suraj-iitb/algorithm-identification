#シェルソート
#挿入ソートは、飛び飛びで値を整列すつもの
#それの飛ぶ範囲をどんどん狭めていって正解を出す
import math

def insertionsort(list, length, g, count):
    for i in range(g, length):
        v = list[i]
        j = i - g
        while j >= 0 and list[j] > v:
            list[j+g] = list[j]
            j = j - g
            count += 1
        list[j+g] = v

    return list, count

def shellsort(list, length):
    count = 0
    g_list = [1]
    g_cell = 4
    while g_cell < length:
        g_list.append(g_cell)
        g_cell = g_cell * 3 + 1

    g_list.reverse()
    print(len(g_list))
    result = ''
    for g in g_list:
        result += str(g) + ' '
    print(result[:-1])

    for g in g_list:
        list, count = insertionsort(list, length, g, count)

    return list, count

l = int(input())
target = []
for i in range(l):
    target.append(int(input()))

result, count = shellsort(target, l)
print(count)
for r in result:
    print(r)

