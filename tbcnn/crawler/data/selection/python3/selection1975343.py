length = int(input())
targ = [int(n) for n in input().split(' ')]
ans = 0
for l in range(length):
    value = l
    for init in range(l + 1,length):
        if targ[value] > targ[init]:
            value = init
    if value != l:
        disp = targ[l]
        targ[l] = targ[value]
        targ[value] = disp
        ans += 1
print(' '.join([str(n) for n in targ]))
print(ans)
