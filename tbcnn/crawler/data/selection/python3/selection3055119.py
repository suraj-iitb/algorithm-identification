def selection_sort(lis, l):
    times = 0
    for i in range(0, l - 1):
        minj = i
        minj_cp = minj
        for j in range(i, l):
            if lis[j] < lis[minj]:
                minj = j
        if minj_cp != minj:
            times += 1
        ele = lis[i]
        lis[i] = lis[minj]
        lis[minj] = ele
    return times

inputs = []
while True:
    try:
        inputs.append(input())
    except(EOFError):
        break

ln = int(inputs[0])
li = list(map(int, inputs[1].split()))

t = selection_sort(li, ln)

print(*li)
print(t)

