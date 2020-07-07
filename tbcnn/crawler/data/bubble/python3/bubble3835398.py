num = int(input())

lst = [int(x) for x in input().split()]

def show():
    for i in range(len(lst)):
        print(lst[i], end="")
        if i < len(lst)-1:
            print(" ", end="")
        else:
            print()

f = True
count = 0
while f:
    f = False
    for j in reversed(range(1,len(lst))):
        if lst[j] < lst[j-1]:
            tmp = lst[j]
            lst[j] = lst[j-1]
            lst[j-1] = tmp
            count += 1
            f = True
show()
print(count)

