def readInt():
  return int(input())


def readInts():
  return [int(i) for i in input().split()]


N = readInt()
AS = readInts()

print(' '.join([str(i) for i in AS]))
for i, a in enumerate(AS[1:]):
    while i >= 0 and AS[i] > a:
        AS[i + 1] = AS[i]
        i -= 1
    AS[i + 1] = a
    print(' '.join([str(i) for i in AS]))

