def readInt():
  return int(input())


def readInts():
  return [int(i) for i in input().split()]


N = readInt()
AS = readInts()

cnt = 0

for i in range(N):
    minj = i
    for j in range(i, N):
        if AS[j] < AS[minj]:
            minj = j
    if i != minj:
        cnt += 1
        AS[i], AS[minj] = AS[minj], AS[i]

print(*AS)
print(cnt)

