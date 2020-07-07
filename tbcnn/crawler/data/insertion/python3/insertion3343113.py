n = int(input())
a = input().split()
print(" ".join(a))
a1 = [a[0]]
a2 = a[1:]
for _ in range(n - 1):
    for j, k in enumerate(a1):
        if int(a2[0]) < int(k):
            if j == 0:
                a1.insert(0, a2[0])
            else:
                a1.insert(j, a2[0])
            break
    else:
        a1.append(a2[0])
    del a2[0]
    print(" ".join(a1 + a2))

