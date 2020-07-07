def display(l):
    for item in l:
        if not item == l[-1]:
            print(f"{item}", end=' ')
        else:
            print(item)


n = int(input())
lst = list(map(int, input().split()))
display(lst)

for i in range(1, len(lst)):
    key = lst[i]
    j = i - 1
    while j >= 0 and lst[j] > key:
        lst[j+1] = lst[j]
        j -= 1
    lst[j+1] = key
    display(lst)
