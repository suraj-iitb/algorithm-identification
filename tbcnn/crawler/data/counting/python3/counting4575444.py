import sys
def input():
    return sys.stdin.readline()[:-1]

input()
C = [0]*10_001

for a in map(int, input().split()):
    C[a] += 1
    
B = []
i = 0
for c in C:
    B += [i]*c
    i += 1
print(*B)
