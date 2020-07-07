def partition(arr, p, r):
    x = arr[r][1]
    i = p - 1
    for j in range(p, r):
        if arr[j][1] <= x:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[r] = arr[r], arr[i+1]
    return i+1

def quick_sort(arr, p, r):
    if p < r:
        q = partition(arr, p, r)
        quick_sort(arr, p, q-1)
        quick_sort(arr, q+1, r)

num = int(input())
card_list = [input().split() for s in range(num)]
card_list = [(t[0], int(t[1])) for t in card_list]
cp_card_list = card_list[:]

quick_sort(card_list, 0, len(card_list) - 1)

is_stable = True
for i in range(len(card_list) - 1):
    if card_list[i][1] == card_list[i+1][1]:
        if cp_card_list.index(card_list[i]) > cp_card_list.index(card_list[i+1]):
            is_stable = False
            break

if is_stable:
    print("Stable")
else:
    print("Not stable")

for t in card_list:
    print(t[0], t[1])


