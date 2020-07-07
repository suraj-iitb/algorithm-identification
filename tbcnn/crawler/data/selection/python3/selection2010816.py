length = int(input())
eles = [int(l) for l in input().split()]
times = 0

for i in range(length-1):
    _min = i
    for j in range(i, length):
        if eles[j] < eles[_min]:
            _min = j
    if i != _min:
        eles[i], eles[_min] = eles[_min], eles[i]
        times += 1

print(*eles)
print(times)
