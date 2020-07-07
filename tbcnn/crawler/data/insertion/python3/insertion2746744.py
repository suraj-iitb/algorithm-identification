N = int(input())
array = list(map(int, input().split()))

y = list(map(str, array))
y = " ".join(y)
print(y)

for i in range(1, N):
    v = array[i]
    j = i - 1
    while j >= 0 and array[j] > v:
        array[j + 1] = array[j]
        j -= 1
        array[j + 1] = v
    x = list(map(str, array))
    x = " ".join(x)
    print(x)

