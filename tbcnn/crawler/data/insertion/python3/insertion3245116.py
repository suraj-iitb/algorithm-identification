n = int(input())

a = input().split()

a = [int(x) for x in a]


for i,x in enumerate(a):
    if i != len(a)-1:
        print(x, end=" ")
    else:
        print(x, end="")
print()

for i in range(1, len(a)):
    v = a[i]
    j = i-1

    while j>= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1

    a[j+1] = v

    for i,x in enumerate(a):
        if i != len(a)-1:
            print(x, end=" ")
        else:
            print(x, end="")
    print()
