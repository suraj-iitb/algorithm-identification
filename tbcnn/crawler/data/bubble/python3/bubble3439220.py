def readInt():
  return int(input())


def readInts():
  return [int(i) for i in input().split()]


N = readInt()
AS = readInts()

flag = True
cnt = 0
i = 0
while flag:
    flag = False
    for i in reversed(range(i + 1, N)):
        if AS[i] < AS[i - 1]:
            AS[i - 1], AS[i] = AS[i], AS[i - 1]
            cnt += 1
            flag = True

print(*AS)
print(cnt)

