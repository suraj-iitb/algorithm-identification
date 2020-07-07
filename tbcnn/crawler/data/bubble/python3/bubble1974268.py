length = int(input())
targ = [int(n) for n in input().split(' ')]
swap = 0
for l in range(length):
    for m in range(l):
        if targ[l - m] < targ[l - m - 1]:
            disp = targ[l-m -1]
            targ[l-m-1] = targ[l-m]
            targ[l-m] = disp
            swap += 1
print(" ".join([str(n) for n in targ]))
print(swap)
