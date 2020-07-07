
def BubleSort(N, data):
    flag = 1
    cnt = 0
    while flag:
        flag = 0
        for i in range(N-1, 0, -1):
            if data[i] < data[i-1]:
                data[i], data[i-1] = data[i-1], data[i]
                flag = 1
                cnt = cnt + 1
    return data, cnt

N = int(input())
data = [ int(i) for i in input().split()]

new_data, cnt = BubleSort(N, data)

for n in range(N):
    if n:
        print(" ", end="")
    print(data[n], end="")
print()
print(cnt)
