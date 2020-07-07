import math
length = int(input())
targ = []
cnt = 0
mcnt = 1
for l in range(length):
    targ.append(int(input()))
m = 1
mlist = [1]
while True:
    m = math.ceil(2.25 * m + 1)
    if length <= m:
        break
    mcnt += 1
    mlist.append(m)
print(mcnt)
print(' '.join([str(n) for n in reversed(mlist)]))
mlength = mcnt - 1
while mlength >= 0:
    m = mlist[mlength]
    divided = length // m
    for inh in range(m,length):
        inlength = inh - m
        temp = targ[inh]
        while inlength >= 0 and temp < targ[inlength]:
            targ[inlength + m] = targ[inlength]
            cnt += 1
            inlength -= m
        targ[inlength + m] = temp
    mlength -= 1
print(cnt)
for l in range(length):
    print(targ[l])
