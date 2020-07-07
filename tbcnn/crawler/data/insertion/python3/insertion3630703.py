def show(lists):
    for i in range(len(lists)):
        if i != len(lists) - 1:
            print(lists[i], end=' ')
        else: print(lists[i])

length = int(input())
List = list(map(int, input().split()))

for i in range(length):
    term = List[i]
    j = i - 1
    while j >= 0 and List[j] > term: #ここで変数をiからjに置き換えないといけない、別のループをするから
        List[j+1] = List[j]
        List[j] = term
        j = j - 1
    show(List)
