num = int(input())

lst = [int(x) for x in input().split()]

def show():
    for i in range(len(lst)):
        print(lst[i], end="")
        if i < len(lst)-1:
            print(" ", end="")
        else:
            print()

count = 0
for i in range(len(lst)):
    minj = i
    for j in range(i,len(lst)):
        if lst[j] < lst[minj]:
            minj = j
    if i != minj:
        tmp = lst[i]
        lst[i] = lst[minj]
        lst[minj] = tmp
        count +=1

show()
print(count)

