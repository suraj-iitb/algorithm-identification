#グローバル変数
count = int()
interval = int()
interval_list = list()

#アルゴリズム：挿入ソート
def insertionSort(list, number, interval):
    for i in range(interval, number):
        v = list[i]
        j = i - interval
        while j >= 0 and list[j] > v:
            list[j + interval] = list[j]
            j = j - interval
            global count
            count += 1
        list[j + interval] = v
    return list

#アルゴリズム：シェルソート
def shellSort(list, number):
    global count, interval, interval_list
    count = 0
    interval = 1
    interval_list.append(1)
    while number >= 3*interval_list[0]+1:
        interval_list.insert(0, 3*interval_list[0]+1)
        interval += 1
    for i in range(interval):
        list = insertionSort(list, number, interval_list[i])
    return list

#初期data
input_number = int(input())
input_list = list()
for i in range(input_number):
    input_list.append(int(input()))

#処理の実行
result_list = list()
result_list = shellSort(input_list, input_number)

#結果の表示
print(interval)
print(" ".join(map(str, interval_list)))
print(count)
[print(i) for i in result_list]

