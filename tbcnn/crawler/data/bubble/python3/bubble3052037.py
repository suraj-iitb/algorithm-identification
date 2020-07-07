def bubble_sort(lis, len):
    flag = 1
    times = 0
    while flag:
        flag = 0
        for i in range(len - 1, 0, -1):
            if lis[i] < lis[i - 1]:
                ele = lis[i]
                lis[i] = lis[i - 1]
                lis[i - 1] = ele
                times += 1
                flag = 1
    return times


inputs = []
while True:
    try:
        inputs.append(input())
    except(EOFError):
        break

ln = int(inputs[0])
li = list(map(int, inputs[1].split()))

t = bubble_sort(li, ln)

print(*li)
print(t)

