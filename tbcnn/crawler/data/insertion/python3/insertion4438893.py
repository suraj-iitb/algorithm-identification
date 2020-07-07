n = int(input())
a_str = input().split()
a = [int(i) for i in a_str]

c = 1
for s in a:
    if c != n:
        print("{} ".format(s), end="")
    elif c == n:
        print(s)
    c += 1

i = 1
while n-1 >= i:
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v

    c = 1
    for s in a:
        if c != n:
            print("{} ".format(s), end="")
        elif c == n:
            print(s)
        c += 1

    i += 1

